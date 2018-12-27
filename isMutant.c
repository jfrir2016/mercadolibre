#include <stdio.h>
#include <math.h>

int isMutant(int N, char adn[N][N])
{
    int cant=0;
    int f,c,e,x;
    char adn2[N][N];
    
//HORIZONTALES
    for(f=0, e=0; f<N; f++)
    {
        for(c=0, e=0; c<(N-1); c++)
        {
            if(adn[f][c] == adn[f][c+1])
                e++;
            else
                e=0;
            if(e==3)
            {
                cant++;
                e=0;
            }
        }
    }
    
//VERTICALES
    for(c=0, e=0; c<N; c++)
    {
        for(f=0, e=0; f<N-1; f++)
        {
            if(adn[f][c] == adn[f+1][c])
                e++;
            else
                e=0;
            if(e==3)
            {
                cant++;
                e=0;
            }
        }
    }
    
//OBLICUAS
    for(f=0; f<N; f++)
    {
        for(c=0; c<N; c++)
            adn2[f][c]=adn[f][(f+c)%N];
    }
    x=N-4;
    for(c=0, e=0; c<(x+1); c++)
    {
        for(f=0, e=0; f<(N-(1+c)); f++)
        {
            if(adn2[f][c] == adn2[f+1][c])
                e++;
            else
                e=0;
            if(e==3)
            {
                cant++;
                e=0;
            }
        }
    }
    for(c=N-x, e=0; c<N; c++)
    {
        for(f=N-c, e=0; f<N-1; f++)
        {
            if(adn2[f][c] == adn2[f+1][c])
                e++;
            else
                e=0;
            if(e==3)
            {
                cant++;
                e=0;
            }
            
        }
    }
    if(cant>1)
        return 1;
    else
        return 0;
}