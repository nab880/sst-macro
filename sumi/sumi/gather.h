#ifndef GATHER_H
#define GATHER_H

#include <sumi/collective.h>
#include <sumi/collective_actor.h>
#include <sumi/collective_message.h>
#include <sumi/comm_functions.h>

DeclareDebugSlot(sumi_gather)

namespace sumi {

class btree_gather_actor :
  public dag_collective_actor
{

 public:
  std::string
  to_string() const {
    return "bruck actor";
  }

  btree_gather_actor(int root) : root_(root) {}

 protected:
  void finalize_buffers();
  void init_buffers(void *dst, void *src);
  void init_dag();
  void init_tree();

  void buffer_action(void *dst_buffer, void *msg_buffer, action* ac);

  void dense_partner_ping_failed(int dense_rank){
    dag_collective_actor::dense_partner_ping_failed(dense_rank);
  }

 private:
  int root_;
  int midpoint_;
  int log2nproc_;

};

class btree_gather :
  public dag_collective
{

 public:
  btree_gather(int root) : root_(root){}

  btree_gather() : root_(-1){}

  std::string
  to_string() const {
    return "allgather";
  }

  dag_collective_actor*
  new_actor() const {
    return new btree_gather_actor(root_);
  }

  dag_collective*
  clone() const {
    return new btree_gather(root_);
  }

  void init_root(int root){
    root_ = root;
  }

 private:
  int root_;

};

}

#endif // GATHER_H