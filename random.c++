#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;


int main() {
 int hp= 70;
 int defense=10;
 int attack = 10;
 int damage = 0;
 bool pPat = false;
 int wpe = 0;
 string userName;

 cout<< "あなたの名前を書いて下さい"<<endl;
 cin>>userName;
  
 srand(static_cast<unsigned int>(time(0)));

 int eHp = rand()%70 +1;//乱数生成
 int eDe = rand()%5 +1;//乱数生成
 int eAt = rand()%12 +1;//乱数生成

  cout<< "敵が現れました"<<endl;
  cout<<"体力"<<eHp<<endl;
  cout<<"防御力:"<<eDe<<endl;
  cout<<"攻撃力:"<<eAt<<endl;

  while(hp >0||eHp >0){
    int critical = rand()%2+1;
    cout<<"あなたのターンです"<<endl;
    cout<<"剣で攻撃しますか？それとも魔法で攻撃しますか？"<<endl;
    if(pPat == false){
       cout<<"(剣で攻撃すると半分の確立でクリティカルが発動し攻撃力が1.4倍、反対に攻撃力が0.7倍になります)"<<endl;
       cout<<"(魔法で攻撃すると攻撃力がそのままです)"<<endl;
       pPat = true;
    }
    cout<<"剣で攻撃する場合は1・魔法で攻撃するときは2を押してください"<<endl;
    cin >> wpe;
    if(wpe == 1 && critical == 1){
      eHp-=attack*1.4;
      cout<<attack*1.4<<"ダメージを与えました"<<endl;
     if(eHp > 0){
        cout<<"敵残りhp"<<eHp<<"です"<<endl;
     }else{
       cout<<"敵を倒しました"<<endl;
     }
    }
    if(wpe == 1 && critical == 2){
     eHp-= attack *0.7;
     cout<<attack*0.7<<"ダメージを与えました"<<endl;
      if(eHp > 0){
        cout<<"敵残りhp"<<eHp<<"です"<<endl;
     }else{
       cout<<"敵を倒しました"<<endl;
     }
    }
    if(wpe == 2){
     eHp-= attack;
     cout<<attack<<"ダメージを与えました"<<endl;
     if(eHp > 0){
        cout<<"敵残りhp"<<eHp<<"です"<<endl;
     }else{
       cout<<"敵を倒しました"<<endl;
     }
    }
    if(eHp>0){
      damage = (defense-eAt);
      hp-=damage;
      cout<<damage<<"ダメージをくらいました"<<endl;
      cout<<"残りhp"<<hp<<"です"<<endl;
    }
    if(hp<0 || eHp<0){
      break;
    }
  }

  if(hp<0){
    cout<<"あなたの負けです";
  }
  if(eHp<0){
    cout<<"あなたの勝ちです"<<endl;
  }
  

}