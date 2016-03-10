/*
 *  This file is part of SST/macroscale:
 *               The macroscale architecture simulator from the SST suite.
 *  Copyright (c) 2009 Sandia Corporation.
 *  This software is distributed under the BSD License.
 *  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
 *  the U.S. Government retains certain rights in this software.
 *  For more information, see the LICENSE file in the top
 *  SST/macroscale directory.
 */

#ifndef SSTMAC_SOFTWARE_LIBRARIES_MPI_MPI_QUEUE_SERVICE_THREAD_MPIQUEUE_H_INCLUDED
#define SSTMAC_SOFTWARE_LIBRARIES_MPI_MPI_QUEUE_SERVICE_THREAD_MPIQUEUE_H_INCLUDED

#include <sstmac/libraries/mpi/mpi_queue/mpi_queue.h>

namespace sstmac {
namespace sw {

class service_thread_mpi_queue :
  public mpi_queue
{

 public:
  virtual std::string
  to_string() const {
    return "service thread mpi_queue";
  }

  virtual ~service_thread_mpi_queue() throw();

  virtual timestamp progress_loop(mpi_request* req);

  virtual void
  start_progress_loop(const std::vector<mpi_request*>& req);

  virtual void
  start_progress_loop(const std::vector<mpi_request*>& req,
                      timestamp timeout);

  virtual void
  finish_progress_loop(const std::vector<mpi_request*>& req);

  virtual event_handler*
  progress_done_handler(operating_system* os,
      mpi_request* req);

  virtual void
  incoming_message(mpi_message* message);

  virtual void
  buffered_send(mpi_message* msg);

  virtual void
  buffered_recv(mpi_message* msg,
                mpi_queue_recv_request* req);

  virtual void
  buffer_unexpected(mpi_message* msg);

  virtual void
  post_rdma(mpi_message* msg);

  virtual void
  post_header(mpi_message* msg);

  virtual bool
  is_service_thread() const {
    return true;
  }


 protected:
  void
  check_timeout(const timestamp& t, key* thekey);

  virtual void
  do_send(mpi_message* mess);

  virtual void
  do_recv(mpi_queue_recv_request* req);

};

}
} // end of namespace sstmac


#endif

