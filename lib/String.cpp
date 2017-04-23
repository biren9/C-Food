
#include "String.h"

/*
 * Default constructor.
 * Internal C-String initialization with size 1.
 * Position 0 is set to Nullterminator.
 */
String::String() {
  size = 0;
  str = new char[1];
  str[0] = '\0';
}

/*
 * Char constructor.
 * Internal C-String initialization with size 2.
 * Char is set and tailing Nullterminator is added.
 */
String::String(char c) {
  size = 1;
  str = new char[2];
  str[0] = c;
  str[1] = '\0';
}

/*
 * C-String constructor.
 * Deep copy of C-String is made.
 */
String::String(const char *s) {
  int i;
  size = 0;
  while (*(s + size) != '\0') size++;
  str = new char[size + 1];
  for (i = 0; i <= size; i++) str[i] = s[i];
}

/*
 * Copy constructor
 * Deep copy of given String is made
 */
String::String(const String& s) {
  int i;
  size = s.size;
  str = new char[size + 1];
  for (i = 0; i < size; i++) str[i] = s.str[i];
  str[size] = '\0';
}

/*
 * destructor
 * clean up any allocated memory
 */
String::~String() {
  delete[] str;
}

/*
 * C-String getter
 * returns internal char pointer
 */
char* String::getString() {
  return str;
}

int String::getSize() {
  return size;
}

/*
 * Array operator overload.
 * If index is in range return pointer.
 * Throws out_of_range by illegal access.
 */
char& String::operator[](int index) {
  if (index >= 0 && index < size)
    return str[index];
  throw std::out_of_range("Index out of range");
}

String& String::operator=(const char *s) {
  if ((s != NULL) && (s[0] == '\0')) {
    delete[] str;
    size = 0;
    while (*(s + size) != '\0') size++;
    str = new char[size + 1];
    for (int i = 0; i <= size; i++)  {
      str[i] = s[i];
    }
  }
  return *this;
}


/*
 * assignment operator overload.
 * frees old allocated memory
 * performs deep copy of String s
 * returns itself
 */
String& String::operator=(String& s) {
  if (this != &s) {
    delete[] str;
    int i;
    size = s.size;
    str = new char[size + 1];
    for (i = 0; i < size; i++) str[i] = s.str[i];
    str[size] = '\0';
  }
  return *this;
}

bool String::equals(String& s) {
  if(this->size == s.getSize()) {
    int length = s.getSize();
    for(int i = 0; i < length; i++) {
      if(str[i] != s.str[i]) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

bool String::equals(String s) {
  if(this->size == s.getSize()) {
    int length = s.getSize();
    for(int i = 0; i < length; i++) {
      if(str[i] != s.str[i]) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

/*
 * Concatenation operator overload
 * sufficient amount of memory is allocated
 * both internal C-Strings are copied in sequence
 * old memory id freed
 * returns itself
 */
String& String::operator+=(String& s) {
  int i = 0;

  /* create new C-String */
  char* tmp;
  tmp = new char[size + s.size + 1];

  /* move str to tmp */
  while (i < size) {
    tmp[i] = str[i];
    i++;
  }

  /* move s.str to tmp */
  i = 0;
  while (i < s.size) {
    tmp[i + size] = s.str[i];
    i++;
  }

  tmp[size + s.size] = '\0';
  size += s.size;

  /* free old C-String memory */
  delete[] str;
  str = tmp;

  return *this;
}


String& String::operator+=(String s) {
  int i = 0;

  /* create new C-String */
  char* tmp;
  tmp = new char[size + s.size + 1];

  /* move str to tmp */
  while (i < size) {
    tmp[i] = str[i];
    i++;
  }

  /* move s.str to tmp */
  i = 0;
  while (i < s.size) {
    tmp[i + size] = s.str[i];
    i++;
  }

  tmp[size + s.size] = '\0';
  size += s.size;

  /* free old C-String memory */
  delete[] str;
  str = tmp;

  return *this;
}
/*
 * Outputstream operator overload
 * chars are copied to ostream and returned
 */
std::ostream& operator<< (std::ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }
  return out;
}
