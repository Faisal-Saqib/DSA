const int N=1e6+10;
int phi[N];
void compute_phi() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; i++)
        phi[i] = i - 1;

    for (int i = 2; i < N; i++)
        for (int j = 2 * i; j < N; j += i)
              phi[j] -= phi[i];
}