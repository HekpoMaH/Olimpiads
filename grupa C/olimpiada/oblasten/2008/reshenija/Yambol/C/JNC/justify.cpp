//TASK: justify
//LANG: C++

#include <iostream>
using namespace std;

int main()
{
    char red[61];
    char x;
    int border, fl;
    int wlen, wcount;
    int spacelen, splenost, splen, blankspace;
    int i, j, s, p, n;
    
    cin >> n;
    cin.get( x );
    
    for ( i = 1; i < n; i++ )
    {
        fl = 0;
        wcount = 1;
        wlen = 0;
        spacelen = 0;
        splenost = 0;
        splen = 0;
        blankspace = 0;
        
        do
        {
            cin.get( x );
        }
        while( x == ' ' );
        
        red[0] = x;
        j = 0;
        
        do
        {
            j++;
            cin.get( red[j] );
            if ( red[j] == ' ' )
                fl = 1;
            else
            {
                if ( fl == 1 )
                    wcount++;
                wlen++;
                fl = 0;
            }
        }
        while( red[j] != '\n' );
        
        if ( red[j-1] == ' ' )
            wcount--;
        
        red[j] = '\0';
        
        border = strlen( red ) - 1;
        
        while ( red[ border ] == ' ' )
            border--;
            
        red[border + 1] = '\0';
        
        blankspace = wcount - 1;
        
        spacelen = 60 - wlen;

        if ( spacelen == 0 )
        {
            cout << red << endl;
            continue;
        }
        
        splen = spacelen / blankspace;
        splenost = spacelen - ( splen * blankspace );
        
        s = 0;
        for ( j = 1; j <= splenost; j++ )
        {
            while ( red[s] == ' ' )
                s++;
            
            do
            {
                cout << red[s];
                s++;
            }
            while ( ( red[s] != ' ' ) && ( red[s] != '\0' ) );
            
            for ( p = 1; p <= ( splen + 1 ); p++ )
                cout << " ";
        }
        
        for ( j = ( splenost + 1 ); j <= wcount ; j++ )
        {
            while ( red[s] == ' ' )
                s++;

            do
            {
                cout << red[s];
                s++;
            }
            while ( ( red[s] != ' ' ) && ( red[s] != '\0' ) );
            
            if ( j != wcount )
                for ( p = 1; p <= splen; p++ )
                    cout << " ";
        }
        
        cout << endl;
    }
    
    fl = 0;
    wcount = 1;
    wlen = 0;

    do
    {
        cin.get( x );
    }
    while( x == ' ' );
        
    red[0] = x;
    j = 0;
    
    do
    {
        j++;
        cin.get( red[j] );
        if ( red[j] == ' ' )
        {
            fl = 1;
        }
        else
        {
            if ( fl == 1 )
                wcount++;
            wlen++;
            fl = 0;
        }
    }
    while( red[j] != '\n' );
    
    if ( red[j-1] == ' ' )
        wcount--;
     
    red[j] = '\0';
    
    border = strlen( red ) - 1;
        
    while ( red[ border ] == ' ' )
        border--;
            
    red[border + 1] = '\0';
    
    s = 0;
    
    for ( j = 1; j <= wcount; j++ )
    {
        while ( red[s] == ' ' )
            s++;
        do
        {
            cout << red[s];
            s++;
        }
        while ( ( red[s] != ' ' ) && ( red[s] != '\0' ) );
        
        if ( j != wcount )
            cout << " ";
    }

    cout << endl;
}
