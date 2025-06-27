class PalindromeChecker {
public:
    PalindromeChecker(const std::string& s) : str(s), n(s.length()) {
        computeHashes();
    }

    bool query(int l, int r) {
        if (l < 0 || r >= n || l > r) {
            throw std::out_of_range("Invalid query range");
        }

        long long hashOriginal = getHash(hashPrefixOriginal, l, r);
        long long hashReversed = getHash(hashPrefixReversed, n - r - 1, n - l - 1);
        return hashOriginal == hashReversed;
    }

private:
    std::string str;
    int n;
    std::vector<long long> hashPrefixOriginal;
    std::vector<long long> hashPrefixReversed;
    std::vector<long long> powBase;

    static const long long base = 31;
    static const long long mod = 1e9 + 9;

    void computeHashes() {
        hashPrefixOriginal.resize(n + 1);
        hashPrefixReversed.resize(n + 1);
        powBase.resize(n + 1);
        powBase[0] = 1;

        // Compute hash for the original string
        for (int i = 0; i < n; ++i) {
            hashPrefixOriginal[i + 1] = (hashPrefixOriginal[i] * base + (str[i] - 'a' + 1)) % mod;
            powBase[i + 1] = (powBase[i] * base) % mod;
        }

        // Compute hash for the reversed string
        for (int i = 0; i < n; ++i) {
            hashPrefixReversed[i + 1] = (hashPrefixReversed[i] * base + (str[n - i - 1] - 'a' + 1)) % mod;
        }
    }

    long long getHash(const std::vector<long long>& hashPrefix, int l, int r) {
        return (hashPrefix[r + 1] - (hashPrefix[l] * powBase[r - l + 1]) % mod + mod) % mod;
    }
};