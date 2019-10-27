char* reverseString(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;
    int mid = floor(len / 2);
    --len;
    for (int i = 0; i < mid; ++i) {
        char temp = s[i];
        s[i] = s[len - i];
        s[len - i] = temp;
    }
    return s;
}