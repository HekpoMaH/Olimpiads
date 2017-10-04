#include<iostream>
#include<algorithm>
using namespace std;

int n, m;// n - broi vyrhove m - broi rebra
long long int g[ 1000 ][ 1000 ];/* matrica na sysedstvo, 
                                   long lobg int za6toto pri preteglen graf kydeto nqma rebro
                                   zapylvame s mnogo glqmo 4islo
                                   */
bool used[ 1000 ];// za otbelqzvane na vyrhovete na koito ve4e sme namerili min pytq
int v[ 1000 ];// v nego zapisvame min pytq za vseki vryh
int pred[ 1000 ];// pazin pred6etvenika na i - tiq vryh zada mojem polse da otpe4atame samiq pyt

int main()
{
    cin >> n >> m;
    int a, b, c;
    for ( int i = 0; i <= n; i++ ) 
        for ( int j = 0; j <= n; j++ ) g[ i ][ j ] = 10000000;// zapylvame grafa s mnogo golemi 4isla
    for ( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> c;
        g[ a ][ b ] = c;
        g[ b ][ a ] = c;
    }
    used[ 1 ] = 1;// markirame na4alniq vryh kato poseten v slu4eq e 1 no moje da e koito i da e vryh
    pred[ 1 ] = -1;/* zadavame mu da nqma pred6estvenici 
                     za6toto tava 6te ni e grani4en slu4ei pri otpe4atvaneto*/
    int m, i0 = 0, j0 = 0;// m - za vremennoto min zarstoqnie
    do
    {
        m = 999999;
        for ( int i = 1; i <= n; i++ )
        {
            if ( used[ i ] == 0 )// ako teku6tiq ni vryh e neobhoden
            {
	            for ( int j = 1; j <= n; j++ )/* tyrsim obhodenite mu pred6estvenici
	                                             i se ooputvame da optimizirame min pytq do i
	                                             4rez min pytq do obhodeniq prd6estvenik + rebroto*/
            	{
            	    if ( used[ j ] == 1 )
            	    {
	                   if ( m > v[ j ] + g[ i ][ j ] )/* ako dosega namerenoto min razstoqnie
	                                                     e po-golqmo ot min razstoqnieto do i
	                                                     optmizirano 4rez rebroto ot j ( koito ve4e e obhoden )
	                                                     to togava go vzemame kato mi zastoqnie
	                                                     */
	                   {
	                       m = v[ j ] + g[ i ][ j ];
	                       i0 = i;// zapzvame si vyrha do koito sme namerili min pyt
	                       j0 = j;// i vyrha 4rez koito sme go namerili koito mu e pred6etvenik
	                   }
	                }
	           }
            }
        }
        if ( m < 999999 )// ako sme namerili nqkakyv min pyt
        {
            used[ i0 ] = 1;// markirame vyrha do koito sme go amerili kato poseten
            v[ i0 ] = m;// zapazvame min zastoqnieto
            pred[ i0 ] = j0;// i otbelqzvame pred6estvenika mu
        }
    }while( m < 999999 );// cikyla se vyrti dokato namirame min razstoqniq 
    
    for ( int i = 2; i <= n; i++ )// otpe4atvane na pin pytq i samiq pyt
    {
        cout << " Min pyt - " <<  1 << " " << i << " = " << v[ i ] << endl;
        cout << "Pytqt e " << endl;
        
        int k = i;
        while ( k != -1 )// dokato stignem na4alniq vryh 4iito pred6etvenik e -1
        {
            cout << k << " ";//otpe4atvame trku6tiq vryh
            k = pred[ k ];// i se dvijim nagore kym na4alniq vryh
        }
         cout << endl;
    }
    system("pause");
    return 0;
}
/*
5 5
1 2 5
1 3 2
2 3 1
3 4 2
4 5 6

*/
