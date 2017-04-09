//
// Created by ninja on 09.04.2017.
//

#ifndef HASHTABELLE_LISTE_H
#define HASHTABELLE_LISTE_H
class Liste {
    struct InfoNode {
        const char *stringTablePointer;
        InfoNode *prev;
        InfoNode *next;
    };
public:
    Liste();
    bool addEnd(char* value);
    void printList();
private:
    InfoNode *first;
    InfoNode *last;

};
#endif //HASHTABELLE_LISTE_H
