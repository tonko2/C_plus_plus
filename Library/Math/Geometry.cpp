

//幾何ライブラリ

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const double EPS=1e-9;
const double INF=1e10;
const double PI = M_PI;

// 平面上の点
struct Point {
   double x,y;
   Point(double x, double y):x(x),y(y){}
   Point(){}
};

Point operator+(Point a, Point b){
   return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a, Point b){
   return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a, double b){
   return Point(a.x*b,a.y*b);
}

Point operator*(Point a, Point b){
   return Point(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

Point operator/(Point a, double b){
   return Point(a.x / b, a.y / b);
}

// 内積
double dot(Point a, Point b){
   return a.x*b.x+a.y*b.y;
}

// 外積
double cross(Point a, Point b){
   return a.x*b.y-a.y*b.x;
}

// 一致確認
bool operator==(Point a, Point b){
   return a.x == b.x && a.y == b.y;
}

// 角度 π*θ/180.0の値
// 第一、第二事象は正 それ以外は負になるので注意
double atan(Point a){
   return atan2(a.y,a.x);
}

// |a|^2
double norm(Point a){
   //a*b*cosθ = a*a*cos(0) = a^2
   return dot(a,a);
}

// |a|
double abs(Point a){
   return sqrt(norm(a));
}

Point polar(double a, double r){
   return Point(cos(r)*a, sin(r)*a);
}

// 値の一致確認 (誤差考慮)
bool EQ(double a, double b){
   return abs(a-b) < EPS;
}

// 点の90度回転
Point rotate90(Point a){
   return Point(-a.y,a.x);
}

// 点の回転 angleはラジアンで与えられる 180*PI/180 = 3.1415
// x' = x*cosθ-y*sinθ
// y' = x*sinθ+y*cosθ

Point rotate(Point a, double angle){
   Point res;
   res.x = a.x * cos(angle) - a.y * sin(angle);
   res.y = a.x * sin(angle) + a.y * cos(angle);
   return res;  
}

struct Line :vector<Point>{
   Line(Point a = Point(0,0), Point b = Point(0,0)){
   this->push_back(a);
   this->push_back(b);
   }
};

struct Circle: Point {
   double r;
   Circle(Point p = Point(0,0), double r = 0):Point(p),r(r){}
};


// 多角形
typedef vector<Point> Polygon;

// 前後の頂点情報
Point next(Polygon a, int x){
   return a[(x+1) % a.size()];
}

Point prev(Polygon a, int x){
   return a[(x - 1 + a.size()) % a.size()];
}

int ccw(Point a, Point b, Point c){
   b = b - a;
   c = c - a;
   if(cross(b,c) > EPS) return 1; // 反時計周り
   if(cross(b,c) < -EPS) return -1; // 時計周り
   if(dot(b,c) < 0) return 2; //c--a--bがこの順番に一直線上
   if(norm(b) < norm(c)) return -2; // a--b--cが順番に一直線上
   return 0; // a--c--bが一直線上
}

// 写像
Point projection(Line l, Point p){
   double t = dot(p-l[0],l[1]-l[0]) / norm(l[0]-l[1]);
   return l[0] + (l[1] - l[0]) * t;
}

// 反射
Point reflection(Line l, Point p){
   return p + (projection(l,p) - p) * 2;
}

// 直線交差判定
// 同一直線の場合は交差していると判定する
bool is_intersect_LL(Line l, Line m){
   return abs(cross(l[1]-l[0],m[1]-m[0])) > EPS || // 傾きが異なる
      abs(cross(l[1]-l[0],m[1]-m[0])) < EPS;
}

// 直線と線分の交差判定
// 同一直線上にある場合も交差と判定
bool is_intersect_LS(Line l, Line s){
   return cross(l[1]-l[0],s[0]-l[0]) *
      cross(l[1]-l[0],s[1]-l[0]) < EPS;
}

// 直線が線分を含むかの判定
bool is_intersect_LP(Line l, Point p){
   return abs(ccw(l[0],l[1],p)) != 1;
}

// 線分交差判定
bool is_intersect_SS(Line s, Line t){
   return ccw(s[0],s[1],t[0]) * ccw(s[0],s[1],t[1]) <= 0 &&
      ccw(t[0],t[1],s[0]) * ccw(t[0],t[1],s[1]) <= 0;
}

// 線分が直線を含むかどうか
bool is_intersect_SP(Line l, Point p){
   return ccw(l[0],l[1],p) == 0;
}

// 円が点を含むかどうか (境界含む EPSに注意)
bool is_intersect_CP(Circle c, Point p){
   return abs(c-p) <= c.r + EPS;
}

//円と線分の交点の数
int intersectCS(Circle c, Line l){
    if(norm(projection(l, c) - c) - c.r*c.r > EPS) return 0;
    double d1 = abs(c - l[0]);
    double d2 = abs(c - l[1]);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if((d1 < c.r - EPS && d2 > c.r + EPS)
       || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;
    Point h = projection(l, c);
    if(dot(l[0] - h, l[1] - h) < 0) return 2;
    return 0;
}

// 2円が共有点を持つかどうか (EPSに注意)
bool is_intersect_CC(Circle c, Circle d){
   return abs(c-d) <= c.r + d.r &&
                    abs(c-d) >= abs(c.r-d.r);
}



// 直線と点の距離
double distance_LP(Line l, Point p){
   return abs(p - projection(l,p));
}

// 直線と直線の距離
double distance_LL(Line l, Line m){
   return is_intersect_LL(l,m) ? 0 : distance_LP(l,m[0]);
}

// 直線と線分の距離
double distance_LS(Line l, Line s){
   if(is_intersect_LS(l,s)) return 0;
   return min(distance_LP(l,s[0]),distance_LP(l,s[1]));
}

// 線分と点の距離
double distance_SP(Line s, Point p){
   Point r = projection(s,p);
   if(is_intersect_SP(s,r)) return abs(r-p);
   return min(abs(s[0]-p),abs(s[1]-p));
}

// 線分同士の距離
double distance_SS(Line s, Line t){
   if(is_intersect_SS(s,t)) return 0;
   return min(min(distance_SP(s,t[0]),distance_SP(s,t[1])),
              min(distance_SP(t,s[0]),distance_SP(t,s[1])));
}

// 直線の交点
Point crosspoint_LL(Line l, Line m){
   double d = cross(m[1]-m[0],l[1]-l[0]);
   if(abs(d) < EPS) throw "線分が平行です";
   return l[0] + (l[1]-l[0]) * cross(m[1]-m[0],m[1]-l[0]) *
      (1.0 / d);
}

// 2円の交点
vector<Point> crosspoint_CC(Circle c1, Circle c2){
   vector<Point> res;
   if(abs(c1-c2) < EPS) return vector<Point>(); //交点が絶対にない
   double d = abs(c1-c2);
   double rc = (d*d+c1.r*c1.r-c2.r*c2.r)/(2*d);
   double rs = sqrt(c1.r*c1.r-rc*rc);
   Point diff = (c2 - c1) / d;
   res.push_back(Point(c1 + diff * Point(rc,rs)));
   res.push_back(Point(c1 + diff * Point(rc,-rs)));
   return res;
}

// 円と線分の直線
vector<Point> crosspoint_CL(Circle a, Line b){
   vector<Point>res;
   double dist = distance_LP(b,a);
   if(dist <= a.r){
      Point s = projection(b,a);
      dist = sqrt(a.r*a.r-dist*dist);
      Point t = (b[1]-b[0])/abs(b[1]-b[0]);
      res.push_back(s+t*dist);
      res.push_back(s-t*dist);
   }
   return res;
}

// 点pから引いた円の接点
vector<Point> tangentCP(Circle c, Point p){
   double x = norm(p-c);
   double d = x - c.r * c.r;
   if(d < -EPS) return vector<Point>();
   d = max(d,0.0);
   Point q1 = (p - c) * (c.r * c.r / x);
   Point q2 = rotate90((p - c) * (-c.r * sqrt(d) / x));
   vector<Point>ret;
   ret.push_back(c + q1 - q2);
   ret.push_back(c + q1 + q2);
   return ret;
}

// 2円の共通接線を求める
vector<Line> tangentCC(Circle a, Circle b){
   vector<Line> list;
   // 外接線の計算
   if(abs(a.r-b.r) < EPS){ // 2円の半径が同じ
      Point dir = b - a;
      dir = rotate90(dir * (a.r / abs(dir)));
      list.push_back(Line(a + dir, b + dir));
      list.push_back(Line(a - dir, b - dir));
   } else {
      Point p = (a * (-b.r)) + (b * a.r);
      p =  p * (1 / (a.r - b.r));
      vector<Point> ps = tangentCP(a,p);
      vector<Point> qs = tangentCP(b,p);
      for(int i=0; i<min(ps.size(),qs.size()); i++){
         list.push_back(Line(ps[i],qs[i]));
      }
   }

   //内接線の計算
   Point p = (a * b.r) + (b * a.r);
   p = p * (1 / (a.r + b.r));
   vector<Point>ps = tangentCP(a,p);
   vector<Point>qs = tangentCP(b,p);
   for(int i=0; i<min(ps.size(),qs.size()); i++){
      list.push_back(Line(ps[i],qs[i]));
   }
   return list;
}

// 多角形の面積
double area(Polygon a){
   double ret = 0.0;
   for(int i=0; i<a.size(); i++){
      ret += cross(a[i],a[(i+1)%a.size()]);
   }
   return abs(ret) * 0.5;
}

// 多角形の重心
Point center_of_gravity(Polygon P){
   Point p;
   for(int i=0; i<P.size(); i++) p = p + P[i];
   return p * (1.0 / P.size());
}

//多角形の中に点があるか 線分を含まない
bool isInside(Polygon gon, Point p ){
   int array[1000];
   fill(array,array+1000,0);
   for ( int i = 0; i < gon.size(); i++ ){
      array[i] = ccw(gon[i], gon[(i+1)%gon.size()], p);
   }
   for(int i=0; i<gon.size()-1; i++){
      if(array[i] != array[i+1]) return false;
   }
   return (true);
}

// 線分と三角形の交差判定
bool is_intersectLT(Line l, Point a, Point b, Point c){
   if(ccw(l[0],l[1],a) * ccw(l[0],l[1],b) < 0 &&
      ccw(l[0],l[1],b) * ccw(l[0],l[1],c) < 0 &&
      ccw(l[0],l[1],c) * ccw(l[0],l[1],a) < 0) return true;
   return false;
}

//凸多角形の切断       線分lで切って、残った左側をQにいれる
Polygon convex_cut(const Polygon& P, const Line& l) {
  Polygon Q;
  for (int i = 0; i < P.size(); ++i) {
     Point A = P[i], B = P[(i+1)%P.size()];
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspoint_LL(Line(A, B), l));
  }
  return Q;
}

//線分sをd平行移動する
Line shift(Line s, double d ){
    Point v = polar(d,atan(s[1]-s[0])+acos(-1)/2 );
    Line m = Line(s[0]+v,s[1]+v);
    return m;
}

//球座標
struct Point2 {
   double x,y,z;
   double r; //半径
   Point2(){}
   Point2 (double theta, double phi){
      x = r*sin(theta)*cos(phi);
      y = r*sin(theta)*sin(phi);
      z = r*cos(theta);     
   }
};

//3次元距離
double getDist(Point2 a, Point2 b){
   return sqrt(pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0) + pow(a.z-b.z,2.0));
}

//余弦定理
double arg2(double a, double b, double c){
   return acos((b*b+c*c-a*a)/(2*b*c));
}

int main(){
   Point a,b;
   cin >> a.x >> a.y;
   cin >> b.x >> b.y;
   cout << norm(a) << endl;
   return 0;
}
