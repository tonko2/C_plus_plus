vector<int>vx;
vector<int>vy;

for(int i=0; i<n; i++){
   cin >> a[i].x >> a[i].y >> a[i].x2 >> a[i].y2;
   vx.push_back(a[i].x);
   vy.push_back(a[i].y);
   vx.push_back(a[i].x2);
   vy.push_back(a[i].y2);
}

vx.push_back(0),vy.push_back(0);
vx.push_back(W),vy.push_back(H);
     
sort(vx.begin(),vx.end());
sort(vy.begin(),vy.end());
vx.erase(unique(vx.begin(),vx.end()),vx.end());
vy.erase(unique(vy.begin(),vy.end()),vy.end());


int x1[1001],x2[1001],y1[1001],y2[1001];

for(int i=0; i<n; i++){
   x1[i] = lower_bound(vx.begin(),vx.end(),a[i].x)-vx.begin();
   x2[i] = lower_bound(vx.begin(),vx.end(),a[i].x2)-vx.begin();
   y1[i] = lower_bound(vy.begin(),vy.end(),a[i].y)-vy.begin();
   y2[i] = lower_bound(vy.begin(),vy.end(),a[i].y2)-vy.begin();
}
