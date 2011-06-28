#ifndef FIBERPROCESSING_H
#define FIBERPROCESSING_H

#include <string>
#include <cmath>
#include <memory>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

#include <itkSpatialObjectReader.h>
#include <itkSpatialObjectWriter.h>

#include "dtitypes.h"

class fiberprocessing{

 public:
  fiberprocessing();
  ~fiberprocessing();

  //Main functions
  void fiberprocessing_main(std::string input_file,bool planeautoOn, std::string plane_file, bool worldspace, int param, std::string param_str);
  void arc_length_parametrization(GroupType::Pointer group, bool worldspace, itk::Vector<double,3> spacing, itk::Vector<double,3> offset, int param, std::string param_str);

  //IO functions
  bool read_plane_details(std::string plane_str, itk::Vector<double,3> spacing, itk::Vector<double,3> offset, bool worldspace);
  void writeFiberFile(const std::string & filename, GroupType::Pointer fibergroup);
  GroupType::Pointer readFiberFile(std::string filename);

  //Helper functions
  void find_distance_from_plane(itk::Point<double, 3> pos, int index);
  void find_plane(GroupType::Pointer group);
  itk::Vector<double, 3> get_plane_origin();
  itk::Vector<double, 3> get_plane_normal();
  std::vector< std::vector<double> > get_arc_length_parametrized_fiber(int param);

 private:
  double SQ2(double x) {return x*x;};

  //Variables
  itk::Vector<double, 3> plane_origin, plane_normal;
  itk::Point<double, 3> closest_point;
  std::vector< std::vector<double> > length, all;
  double closest_d;
  int l_counter;

};


#endif
