string s;
bool isPalindrome(ll l, ll r) {
    while (l <= r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}