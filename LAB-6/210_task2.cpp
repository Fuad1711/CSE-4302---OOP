#include<iostream>
using namespace std;

class SocialPost {
private:
    int userID;
    int likes;
    int shares;

public:
    SocialPost() : userID(), likes(), shares() {}
    SocialPost(int id, int like, int share) : userID(id), likes(like), shares(share) {}
    ~SocialPost(){
        
    }
    int getid() const{ return userID;}
    int getlikes() const{ return likes;}
    int getshares() const{ return shares; }
    int getviralscore() const{ return likes * 1 + shares * 3;}
    void setid(int id){
        userID = id;
    }
    void setlikes(int like){
        likes = like;
    }
    void setshares(int share){
        shares = share;
    }
    void operator += (int n){
        likes = likes + n;
    }
    void operator-=(int n){
        likes = likes - n;
    }
    bool operator == (SocialPost &p) const{
        return p.getlikes() == p.getshares();
    }
    bool operator > (SocialPost &p) const{
        return this->getviralscore() > p.getviralscore();
    }
    bool operator < (SocialPost &p) const{
        return this->getviralscore() < p.getviralscore();
    }

    void display() const{
        cout << userID << "like count: " << getlikes() << endl;
        cout << "share count: " << getshares() << endl;
        cout << "score: " << getviralscore() << endl;
    }
};
int main(){

    SocialPost post1, post2;
    post1 += 50;
    cout << post1.getlikes() << endl;
    if(post1 > post2) cout << "Post 1 is trending!";
    else cout << "Post 2 is trending";



}