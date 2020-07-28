string s;
        int cnt1 = 0, cnt2 = 0;
        for(char c: s) {
            if(c == 'B') cnt1++;
            else if(c == '.') cnt2++;
        }

        if(cnt1 >= cnt2) cout<<"Y\n";
        else cout<<"N\n";