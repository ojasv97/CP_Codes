#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int s[1000];
    int e[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&e[i]);
    }
    int map[1001];
    for(int i=0;i<1001;i++){
        map[i]=0;
    }
    int start,end;
    for(int i=0;i<n;i++){
        start = s[i];
        end = e[i];
        for(int j=start;j<=end;j++){
            map[j]++;
        }
    }
    int mx=-1;
    int stamp=-1;
    for(int i=1;i<1001;i++){
        stamp = map[i]>mx?i:stamp;
        mx = map[i]>mx?map[i]:mx;
    }
    printf("%d",stamp);
    return 0;
}
