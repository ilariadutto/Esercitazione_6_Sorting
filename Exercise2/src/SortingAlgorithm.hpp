#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {


template<typename T>
void BubbleSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	
	for (unsigned int i = 0; i < n - 1; i++)
	{	
		for (unsigned int j = i + 1; j < n ; j++)
		{	
			if (v[j] < v[i])
			{ 	//swap:
				T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
		}
	}
			
	
}


template<typename T>
void maintain_heap(std::vector<T>& v, int n, int i) {
    int nMax = i;  // Inizializzo il nodo più grande come radice
    int nLeft = 2 * i + 1;  // Figlio sinistro
    int nRight = 2 * i + 2; // Figlio destro

    // Se il figlio sinistro è più grande della radice
    if (nLeft < n && v[nLeft] > v[nMax]){
        nMax = nLeft;
	}

    // Se il figlio destro è più grande della radice (o figlio sinistro)
    if (nRight < n && v[nRight] > v[nMax]) {
        nMax = nRight;
	}

    // Se il nodo più grande non è la radice, scambia 
    if (nMax != i) {
        //swap(v[i], v[nMax]);
		T tmp = v[i];
        v[i] = v[nMax];
        v[nMax] = tmp;
		
        maintain_heap(v, n, nMax);  // Ricorsione per il sottoalbero
    }
}


template<typename T>
void HeapSort(std::vector<T>& v)
{
    
    int n = v.size();

    // a partire da n / 2 - 1 che è il primo nodo non foglia faccio diventare il vettore a un heap 
    for (int i = n / 2 - 1; i >= 0; i--) {
        maintain_heap(v, n, i);  //  controllo sottoalbero sia una max-heap
    }

    // estrazione degli elementi dalla heap 
    for (int i = n - 1; i > 0; i--) {
        // Sposto l'elemento massimo (radice) alla fine
        //swap(v[0], v[i]);
		
		T tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;

        // ricostruisco la heap con l'elemento rimosso
        maintain_heap(v, i, 0);
    }
	

    
}
		
	


}


