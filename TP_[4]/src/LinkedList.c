#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
		this->size = 0;
		this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	retorno = this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* indice = NULL;
	int len;
	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);
		if(len >= 0 && nodeIndex < len)
		{
			for(int i = 0; i < len; i++)
			{
				if(i == 0)
				{
					indice = this->pFirstNode;
				}
				else
				{
					indice = indice->pNextNode;
				}
				if(i == nodeIndex)
				{
					break;
				}
			}
		}
	}

    return indice;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;
    Node* nuevoNodo;
    int len;
    if(this != NULL)
    {
		len = ll_len(this);
		if(len >= 0)
		{
			if(nodeIndex > -1 && nodeIndex <= len)
			{
				nuevoNodo = (Node*) malloc (sizeof(Node));
				if(nuevoNodo != NULL)
				{
					if(len == 0 || nodeIndex == 0)
					{
						if(this->pFirstNode != NULL)
						{
							nuevoNodo->pNextNode = this->pFirstNode;
						}
						else
						{
							nuevoNodo->pNextNode = NULL;
						}
						this->size++;
						this->pFirstNode = nuevoNodo;
						nuevoNodo->pElement = pElement;
					}
					else
					{
						Node* indice;
						indice = getNode(this, nodeIndex - 1);
						if(indice != NULL)
						{
							this->size++;
							indice->pNextNode = nuevoNodo;
							nuevoNodo->pElement = pElement;
							nuevoNodo->pNextNode = NULL;
						}
					}
					retorno = 0;
				}

			}
		}
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	int len;
    	len = ll_len(this);
    	if(len >= 0)
    	{
			if(addNode(this, len, pElement) == 0)
			{
				retorno = 0;
			}
    	}
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;

    if(this != NULL && index >= 0)
    {
    	Node* nodo;

    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		retorno = nodo->pElement;
    	}
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	Node* modificarNodo;

    	modificarNodo = getNode(this, index);

    	if(modificarNodo != NULL)
    	{
    		modificarNodo->pElement = pElement;
    		retorno = 0;
    	}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	Node* posteriorNodo;
    	Node* anteriorNodo;

		posteriorNodo = getNode(this, index + 1);
    	if(index == 0)
    	{
    		this->pFirstNode = posteriorNodo;
    		this->size--;
    		retorno = 0;
    	}
    	else
    	{
			anteriorNodo = getNode(this, index - 1);
			anteriorNodo->pNextNode = posteriorNodo;
			this->size--;
			retorno = 0;
    	}
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    	retorno = 0;
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	free(this);
    	retorno = 0;
    }
    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	Node* nodo;
    	int contador = 0;
    	nodo = this->pFirstNode;
    	while(nodo != NULL)
    	{
			if(nodo->pElement == pElement)
			{
				retorno = contador;
				break;
			}
			else
			{
				nodo = nodo->pNextNode;
				contador++;
			}
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	if(this->size == 0)
    	{
    		retorno = 1;
    	}
    	else
    	{
    		retorno = 0;
    	}
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	Node* nodoAnterior;
    	Node* nodoAgregar;
    	Node* nodoPosterior;

    	nodoAgregar = (Node*) malloc (sizeof(Node));
    	nodoPosterior = getNode(this, index);
    	if(index == 0)
    	{
    		nodoAgregar->pNextNode = nodoPosterior;
    		nodoAgregar->pElement = pElement;
    		this->pFirstNode = nodoAgregar;
    		this->size++;
    		retorno = 0;
    	}
    	else
    	{
    		nodoAnterior = getNode(this, index - 1);
    		nodoAgregar->pNextNode = nodoPosterior;
    		nodoAgregar->pElement = pElement;
    		nodoAnterior->pNextNode = nodoAgregar;
    		this->size++;
    		retorno = 0;
    	}
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	Node* nodoPop;
    	Node* nodoAnterior;
    	Node* nodoPosterior;

    	nodoPop = getNode(this, index);
    	nodoPosterior = getNode(this, index + 1);
    	if(nodoPop != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = nodoPosterior;
				this->size--;
				retorno = nodoPop->pElement;
			}
			else
			{
				nodoAnterior = getNode(this, index - 1);

				nodoAnterior->pNextNode = nodoPosterior;
				this->size--;
				retorno = nodoPop->pElement;
			}
    	}
    }
    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	Node* nodo;
    	nodo = this->pFirstNode;
		retorno = 0;
    	while(nodo != NULL)
    	{
    		if(nodo->pElement == pElement)
    		{
				retorno = 1;
    			break;
    		}
    		else
    		{
    			nodo = nodo->pNextNode;
    		}
    	}
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;

    if(this != NULL && this2 != NULL)
    {
    	Node* nodo;
    	Node* nodo2;

		nodo = this->pFirstNode;
		nodo2 = this2->pFirstNode;

		retorno = 0;

		while(nodo != NULL && nodo2 != NULL)
		{
			if(nodo->pElement != nodo2->pElement)
			{
				retorno = 0;
				break;
			}
			else
			{
				nodo = nodo->pNextNode;
				nodo2 = nodo2->pNextNode;
				retorno = 1;
			}
		}

    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && from >= 0 && from < len && to > from && to <= len)
    {
    	Node* nodoAux;

    	cloneArray = ll_newLinkedList();

    	for(int i = from; i < to; i++)
    	{
			nodoAux = getNode(this, i);
			if(nodoAux != NULL)
			{
				if(i == from)
				{
					cloneArray->pFirstNode = nodoAux;
					cloneArray->size++;
				}
				else
				{
					cloneArray->size++;
					nodoAux->pNextNode = nodoAux;
				}
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	cloneArray = this;
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno =-1;

    if(this != NULL)
    {
    	if(pFunc != NULL && (order == 0 || order == 1))
    	{
			int len;
			void* nodo1;
			void* nodo2;
			int respuesta;

			len = ll_len(this);

			if(order == 1)
			{
				for(int i = 0; i < len - 1; i++)
				{
					for(int j = i + 1; j < len; j++)
					{
						nodo1 = ll_get(this, i);
						nodo2 = ll_get(this, j);
						respuesta = pFunc(nodo1,nodo2);
						if(respuesta > 0)
						{
							ll_set(this, i, nodo2);
							ll_set(this, j, nodo1);
						}
						retorno = 0;
					}
				}
			}
			if(order == 0)
			{
				for(int i = 0; i < len - 1; i++)
				{
					for(int j = i + 1; j < len; j++)
					{
						nodo1 = ll_get(this, i);
						nodo2 = ll_get(this, j);
						respuesta = pFunc(nodo1,nodo2);
						if(respuesta < 0)
						{
							ll_set(this, i, nodo2);
							ll_set(this, j, nodo1);
						}
						retorno = 0;
					}
				}
			}
    	}
    }

    return retorno;

}

