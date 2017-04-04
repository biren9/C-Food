# Buffer

### Public methode:



#### Buffer(*char filename)
    
    Basic constructor & destructor
    
    Filelocation as parameter
    
#### char getNextChar()

    Return the next character

#### char getCurrentChar()

    Return the current character
    

#### void ungetChar()

    Go one character back
    
    throw errors:
        -If unget reache a \n
        -Buffer underflow
        
#### unsigned int getRow()

    Return the row for the current character


#### unsigned int getCol()

    Return the column for the current character
