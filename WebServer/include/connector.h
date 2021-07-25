/*
 * author: 657023321@qq.com
 * date: 2020-02-19
 * function: the class of action entity of socket connecting
 */

#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include <common.h>

/* we assume that one server just has one Connector, so that it is a single class */
class Connector {
 public:
  static Connector *CreateConnector(int port, Server *server, 
    Epoller *epoller, int listen_cnt);
  int Connect(Epoller *epoller);
  ~Connector();
  
 private:
  Connector(int port, Server *server, Epoller *epoller, int listen_cnt);

  const int port_;
  const int listen_cnt_;
  Server *server_;
  Epoller *epoller_;
  int fd_;
};

#endif /* _CONNECTOR_H_ */

