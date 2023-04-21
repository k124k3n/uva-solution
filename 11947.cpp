#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll diy[12] = {31,30,31,30,31,30,31,31,30,31,30,31};
ll num;
ll d,m,y;

void check(){
    bool leap = (y%400==0) || ((y%4==0) && (y%100!=0));
    if(leap) diy[1] = 29;
    else diy[1] = 28;

    while(m <= 12 && num >= diy[m-1]){
        num -= diy[m-1];
        ++m;
    }

    if(m == 13){
        ++y;
        m = 1;
    }

    leap = (y%400==0) || ((y%4==0) && (y%100!=0));
    if(leap) diy[1] = 29;
    else diy[1] = 28;

    while(m <= 12 && num >= diy[m-1]){
        num -= diy[m-1];
        ++m;
    }

    d += num;

    // cout << d << " " << m << " " << y << "\n";

}

int main(){
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    ll cs = 0;
    while(n--){
        scanf("%2lld%2lld%4lld", &m, &d, &y);
        // printf("date awal = %lld %lld %lld\n", d, m, y );
        string zodiac[12] = {"aquarius", "pisces", "aries", "taurus",  "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};

        num = 280;
        bool leap = (y%400==0) || ((y%4==0) && (y%100!=0));
        if(leap) diy[1] = 29;
        else diy[1] = 28;

        num -= diy[m-1] - d + 1;
        if(m==12){
            m = 1;
            ++y;
        }

        else ++m;
        d=1;
        
        check();
        /*
        Aquarius January, 21 February, 19
Pisces February, 20 March, 20
Aries March, 21 April, 20
Taurus April, 21 May, 21
Gemini May, 22 June, 21
Cancer June, 22 July, 22
Leo July, 23 August, 21
Virgo August, 22 September, 23
Libra September, 24 October, 23
Scorpio October, 24 November, 22
Sagittarius November, 23 December, 22
Capricorn December, 23 January, 20
        */
        ll mnt = 0;

        if((m==1 && d>=21) || (m==2 && d<=19)) mnt = 0;
        else if((m==2 && d>=20) || (m==3 && d<=20)) mnt = 1;
        else if((m==3 && d>=21) || (m==4 && d<=20)) mnt = 2;
        else if((m==4 && d>=21) || (m==5 && d<=21)) mnt = 3;
        else if((m==5 && d>=22) || (m==6 && d<=21)) mnt = 4;
        else if((m==6 && d>=22) || (m==7 && d<=22)) mnt = 5;
        else if((m==7 && d>=23) || (m==8 && d<=21)) mnt = 6;
        else if((m==8 && d>=22) || (m==9 && d<=23)) mnt = 7;
        else if((m==9 && d>=24) || (m==10 && d<=23)) mnt = 8;
        else if((m==10 && d>=24) || (m==11 && d<=22)) mnt = 9;
        else if((m==11 && d>=23) || (m==12 && d<=22)) mnt = 10;
        else mnt = 11;

        
        printf("%lld %02lld/%02lld/%04lld %s\n", ++cs, m, d, y, zodiac[mnt].c_str());



        
        
    }
    return 0;
}