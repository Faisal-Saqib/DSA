inline ll read() {
    char c = getchar();
    ll x = 0, s = 1;
    while (c < '0' || c > '9') {
        if (c == '-')
            s = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * s;
}