Union(S, T, U){// set U is used to store union of the set S and T.
    U.add(S);
    for (each x in T ){
        if(!find(x, S)){
            insert(x, U);
        }
    } 	 
}

list<node> assemble (int x, list<node> &L, list<node> &M) {
    list<node> first;
    first->element = x;
    first->next = setUnion(L, M);
    return first;
 }
list<node> setUnion(list<node> L, list<node> M, list<node> U) {
    if (L == NULL && M == NULL){
        return NULL;
    }
    else if (L == NULL){ /* M cannot be NULL here */
        return  assemble(M->element, NULL, M->next);
    }
    else if (M == NULL){ /* L cannot be NULL here */
        return assemble(L->element, L->next, NULL); 
        /* if we reach here, neither L nor M can be NULL */
    }
    else if (L->element == M->element){
        return assemble(L->element, L->next, M->next);
    }
    else if (L->element < M->element){
        return assemble(L->element, L->next, M);
    }
    else{ /* here, M->element < L->element */
        return assemble(M->element, L, M->next);
    }
 }
