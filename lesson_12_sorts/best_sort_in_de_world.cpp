#include <time.h>

template <class T>
void bogo_sort_like(T * arr, int len, T * comp) {
    srand(time(NULL));
    for (int i = 0; i < len; i += 1)
        comp[i] = arr[i];
    int i;
    while (true) {
        for (i = 1; i < len; i += 1)
            if (comp[i] < comp[i - 1])
                break;
        if (i == len)
            break;
        std::swap(comp[rand() % len], comp[rand() % len]);
    }
}