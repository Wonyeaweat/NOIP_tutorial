#include<cstdio>
    using namespace std;
    int i,j,k,n,m,w,ans;
    int main(){
    	freopen("genshin.in","r",stdin);
    	freopen("genshin.out","w",stdout);
    	
        scanf("%d",&n);
        for(i=0;i<3;i++){
            scanf("%d%d",&j,&k);m=j;w=k;//���벢���³�ʼ�ļ۸�������
            while(j<n){j<<=1;k<<=1;}//�۸�����������*2ֱ����������n
            while(j>n){j-=m;k-=w;}//*2�п��ܵ�����̫���ˣ���ȥһЩ
            while(j<n){j+=m;k+=w;}//��ȥ֮���ֿ���̫���ˣ�����һЩ
            //��ʵ���Ǵ���ȵ��ϵ���Ȼ����һЩ΢��
            if(k<ans||ans==0)ans=k;//�ж��Ƿ�����С����
        }
        printf("%d\n",ans);
        return 0;//���������
    }
