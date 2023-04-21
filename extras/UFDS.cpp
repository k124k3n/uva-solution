void flood_fill_4(ll sr, ll sc) {
    queue<ll> Qr; Qr.push(sr);
    queue<ll> Qc; Qc.push(sc);
    visff[sr][sc] = true;

    ll dr[] = {1, 0, -1, 0};
    ll dc[] = {0, 1, 0, -1};
    while (!Qr.empty()) {
        ll cr = Qr.front(); Qr.pop();
        ll cc = Qc.front(); Qc.pop();
        for (ll i = 0; i < 4; i++) {
            ll nr = cr + dr[i];
            ll nc = cc + dc[i];
            // constraint > 0
            if (visff[nr][nc]) continue;

            Qr.push(nr);
            Qc.push(nc);
            visff[nr][nc] = true;
        }
    }
}