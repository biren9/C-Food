

#ifndef MYSTRING
#define MYSTRING
#include <iostream>
#include <stdexcept>


/* String
 * ======
 * implementation of a String class in cpp.
 * String is handled internally as a C-String.
 *
 * Instanciation of an object is possible as:
 *   - empty String
 *   - single Char
 *   - C-String
 *   - copy of String
 *
 * possible operations on String class are:
 *   - array access
 *   - assignment
 *   - concatenation
 */
class String {
private:
  /* 'String' is represented internally as a plain C-style string. */
  int size;
  char* str;

public:
  /*
   * @brief default constructor
   */
  String();

  /*
   * @brief char constructor
   * @param c char to initialize string
   */
  String(char c);

  /*
   * @brief C-String constructor
   * @param s C-String
   */
  String(const char *s);

  /*
   * @brief Copy constructor
   * @param s String
   */
  String(const String &s);

  /*
   * @brief destructor
   */
  ~String();

  /*
   * @brief get internal C-String
   * @return C-String
   */
  char* getString();

  int getSize();

  /*
   * @brief Array operator overload
   */
  char& operator[] (int index);

  /*
   * @brief assignment operator overload
   */
  String& operator=(String&);

  /*
   * @brief concatenation operator overload
   */
  String& operator+=(String&);

  /*
   * make friend, so we can access private members
   */
  friend std::ostream& operator<< (std::ostream &out, String &s);

  bool equals(String& s);
};
#endif
