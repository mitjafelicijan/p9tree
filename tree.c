#include <u.h>
#include <libc.h>
#include <fcall.h>
#include <thread.h>
#include <9p.h>

void
print_tree(char *basepath, int depth, char *prefix, int max_depth)
{
    Dir *dirs;
    int i, n, fd;
    char *newprefix;

    if (max_depth >= 0 && depth > max_depth)
        return;

    if ((fd = open(basepath, OREAD)) < 0)
        return;

    while ((n = dirread(fd, &dirs)) > 0)
    {
        for (i = 0; i < n; i++)
        {
            Dir *d = &dirs[i];

            if (strcmp(d->name, ".") == 0 || strcmp(d->name, "..") == 0)
                continue;

            if (i == n - 1)
            {
                print("%s└── %s\n", prefix, d->name);
                newprefix = smprint("%s    ", prefix);
            }
            else
            {
                print("%s├── %s\n", prefix, d->name);
                newprefix = smprint("%s│   ", prefix);
            }

            if (d->mode & DMDIR)
            {
                char *newpath = smprint("%s/%s", basepath, d->name);
                print_tree(newpath, depth + 1, newprefix, max_depth);
                free(newpath);
            }
            free(newprefix);
        }
        free(dirs);
    }
    close(fd);
}

void
main(int argc, char *argv[])
{
    int max_depth = -1;
    char *start_dir = ".";

    ARGBEGIN
    {
    case 'L':
        max_depth = atoi(ARGF());
        break;
    default:
        fprint(2, "usage: %s [-L depth] [dir]\n", argv0);
        exits("usage");
    }
    ARGEND

    if (argc > 0)
        start_dir = argv[0];

    print_tree(start_dir, 0, "", max_depth);
    exits(0);
}

