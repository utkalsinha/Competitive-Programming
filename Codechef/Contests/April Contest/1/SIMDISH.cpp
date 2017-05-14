#include <stdio.h>
#include <unordered_map>
#include <string.h>

using namespace std;

#define MAX 11

int main(){
    //freopen("sip.txt", "r", stdin);
   // freopen("sio.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        unordered_map<string, int> hashtable;
        unordered_map<string, int>::const_iterator it;
        int c = 4;
        int cnt = 0;
        char str[MAX];
        while(c--){
            scanf("%s",str);
            hashtable.insert({str,1});
        }
        c = 4;
        while(c--){
            scanf("%s",str);
            it = hashtable.find(str);
            if(it != hashtable.end()){
                //printf("=>%s\n", it->second);
                cnt++;
            }
        }
        if(cnt >=2) printf("similar");
        else printf("dissimilar");
        printf("\n");
    }
  //  fclose(stdout);
  //  fclose(stdin);
    return 0;
}



