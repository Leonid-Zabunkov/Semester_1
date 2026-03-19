class string {
public:
  string(char *s) : _s(s), _len(getLen(s)) {}

  bool operator==(char *s) {
    int i = 0;
    while ((s[i] == _s[i]) && s[i] != '\0') {
      i++;
    }
    
    return s[i] == '\0';
  }

private:
  int getLen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
      i++;
    }
    return i;
  }

  char *_s;
  int _len;
};