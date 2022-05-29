#ifndef DataType_
#define DataType_

// object in each binary node
class DataType {
  friend ostream& operator<<(ostream&, DataType);
 public:
  operator int() const {return key;}  // casting the object to int
  int key;  // element key
  char ID;  // element identifier or record
};

ostream& operator<<(ostream& out, DataType x)
{out << x.key << ' ' << x.ID << ' '; return out;}

#endif
