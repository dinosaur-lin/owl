#!/usr/bin/env owl
(* This example demonstrates the use of OpenCL's Ndarray module *)

#require "owl-opencl"
open Owl

module M = Owl_computation_opencl_engine.Make (Dense.Ndarray.S);;


let test_01 () =
  let x = M.var_elt "x" in
  let y = M.const_elt "y" 1. in
  M.assign_elt x 2.;
  let w = M.Scalar.sin x in
  let z = M.Scalar.add w y in
  M.eval_elt ~dev_id:1 [|z|];
  let a = M.unpack_elt z in
  Owl_log.info "a = %g" a


let test_02 a =
  let x = M.ones [|3; 4|] in
  let y = M.uniform [|3; 4|] in
  let z = M.add x y in
  M.eval_arr ~dev_id:1 [|z|];
  let a = M.unpack_arr z in
  Dense.Ndarray.S.print a


let _ =
  Owl_log.(set_level DEBUG);
  test_02 ()