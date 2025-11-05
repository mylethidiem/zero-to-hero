#ifndef __SHARE_POINER_H__
#define __SHARE_POINER_H__

class SharePointer {
private:
  static SharePointer *m_Instance;

public:
  static SharePointer *getInstance();
  void usingSharePointer();
};

#endif //__SHARE_POINER_H__
