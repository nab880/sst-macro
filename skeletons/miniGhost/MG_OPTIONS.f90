! ************************************************************************
!
!               miniGhost: stencil computations with boundary exchange.
!                 Copyright (2011) Sandia Corporation
!
! Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
! license for use of this work by or on behalf of the U.S. Government.
!
! This library is free software; you can redistribute it and/or modify
! it under the terms of the GNU Lesser General Public License as
! published by the Free Software Foundation; either version 2.1 of the
! License, or (at your option) any later version.
!
! This library is distributed in the hope that it will be useful, but
! WITHOUT ANY WARRANTY; without even the implied warranty of
! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
! Lesser General Public License for more details.
!
! You should have received a copy of the GNU Lesser General Public
! License along with this library; if not, write to the Free Software
! Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
! USA
! Questions? Contact Richard F. Barrett (rfbarre@sandia.gov) or
!                    Michael A. Heroux (maherou@sandia.gov)
!
! ************************************************************************
 
MODULE MG_OPTIONS_MOD

   USE MG_CONSTANTS_MOD

   IMPLICIT NONE

   LOGICAL :: &
      CHECK_DIFFUSION      ! Correctness checking

   INTEGER :: SCALING

   INTEGER, PARAMETER ::      &
      SCALING_STRONG   = 1,                &
      SCALING_WEAK     = 2

   INTEGER :: COMM_METHOD

   INTEGER, PARAMETER ::      &

      COMM_METHOD_BSPMA = 1,            &
      COMM_METHOD_SVAF  = 2,            &
      COMM_METHOD_SVCP  = 3

   INTEGER :: STENCIL

   INTEGER, PARAMETER ::      &

      STENCIL_NONE         = 10,           &
      STENCIL_2D5PT        = 11,           &
      STENCIL_2D9PT        = 12,           &
      STENCIL_3D7PT        = 13,           &
      STENCIL_3D27PT       = 14

   INTEGER :: SEND_PROTOCOL

   INTEGER, PARAMETER ::      &

      SEND_PROTOCOL_BLOCKING    = 21,      &
      SEND_PROTOCOL_NONBLOCKING = 22

   ! ---------
   ! Variables
   ! ---------

   INTEGER ::         &

      NUM_SPIKES,                  &  ! Number of spikes to be inserted.

      NPX, NPY, NPZ,               &  ! Number of processes in direction X, Y, Z

      NX, NY, NZ,                  &  ! Global domain dimensions.
      NUM_VARS,                    &  ! Number of variables defined.
      NUM_TSTEPS,                  &  ! Number of time steps to be executed.
      PERCENT_SUM                     ! Requested percentage of variables to be globally summed.

END MODULE MG_OPTIONS_MOD