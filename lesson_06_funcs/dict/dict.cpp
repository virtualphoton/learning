#include <iostream>
#include <cctype>

/*
* get value from string array of format "key=val"
* args:
*   array, const char **
*   its length, int
*   key to find, const char *
*   buffer to write into(memory has to be already allocacted), char *
*/

const char * to_lower(const char * str) {
    int len = strlen(str);
    char * new_str = new char[len+1];
    new_str[len] = '\0';
    for (int i = 0; i < len; i += 1)
        new_str[i] = std::tolower(str[i]);
    return new_str;
}

const char * get_key(const char * str) {
    int len = strlen(str);
    int i = 0;
    for (; i < len; i += 1)
        if (str[i] == '=')
            break;

    char * new_str = new char[i + 1];
    new_str[i] = '\0';
    for (int j = 0; j < i; j += 1)
        new_str[j] = str[j];
    return new_str;
}

const char * get_val(const char * str) {
    int len = strlen(str);
    int i = 0;
    for (; i < len; i += 1)
        if (str[i] == '=')
            break;

    int new_len = len - i - 1;
    char * new_str = new char[new_len+1];
    new_str[new_len] = '\0';
    for (int j = 0; j < new_len; j += 1)
        new_str[j] = str[j+i+1];
    return new_str;
}

bool check_eq(const char * a, const char * b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    if (len1 == len2) {
        for (int i = 0; i < len1; i += 1)
            if (a[i] != b[i])
                return false;
        return true;
    }
    return false;
}

bool find_value(const char ** arr, int arr_len, const char* name, char * buf) {
    bool ret = false;
    const char * key;
    const char * val;
    const char * lowered;
    name = to_lower(name);
    for (int ind = 0; ind < arr_len; ind += 1) {
        lowered = to_lower(arr[ind]);
        key = get_key(lowered);
        val = get_val(lowered);
        if (check_eq(key, name)) {
            int len_buf = strlen(buf);
            int len_val = strlen(val);
            for (int i = 0; i < len_buf and i < len_val; i += 1)
                buf[i] = val[i];
            ret = true;
        }
        delete[] lowered;
        delete[] key;
        delete[] val;
        if (ret)
            return true;
    }
    return false;
}