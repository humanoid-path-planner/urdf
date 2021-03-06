/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2008, Willow Garage, Inc.
*  All rights reserved.
* 
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
* 
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Wim Meeussen */

#include "urdf/model.h"
#include <console_bridge/console.h>

/* we include the default parser for plain URDF files; 
   other parsers are loaded via plugins (if available) */
#include <urdf_parser/urdf_parser.h>
//#include <urdf_parser_plugin/parser.h>
//#include <pluginlib/class_loader.h>

#include <boost/scoped_ptr.hpp>
#include <boost/thread.hpp>

#include <vector>
#include <fstream>
#include <iostream>

namespace urdf{

static bool IsColladaData(const std::string& data)
{
  return data.find("<COLLADA") != std::string::npos;
}


bool Model::initFile(const std::string& filename)
{
  std::ostringstream oss;
  oss << __FILE__ << ":" << __LINE__
      << ": not implemented.";
  throw std::runtime_error (oss.str ().c_str ());
}

bool Model::initParam(const std::string& param)
{
  std::ostringstream oss;
  oss << __FILE__ << ":" << __LINE__
      << ": not implemented.";
  throw std::runtime_error (oss.str ().c_str ());
}

bool Model::initXml(TiXmlDocument *xml_doc)
{
  std::ostringstream oss;
  oss << __FILE__ << ":" << __LINE__
      << ": not implemented.";
  throw std::runtime_error (oss.str ().c_str ());
}

bool Model::initXml(TiXmlElement *robot_xml)
{
  std::ostringstream oss;
  oss << __FILE__ << ":" << __LINE__
      << ": not implemented.";
  throw std::runtime_error (oss.str ().c_str ());
}

bool Model::initString(const std::string& xml_string)
{
  boost::shared_ptr<ModelInterface> model;

  // necessary for COLLADA compatibility
  if( IsColladaData(xml_string) ) {
    std::ostringstream oss;
    oss << __FILE__ << ":" << __LINE__
	<< ": parsing of Colladam not implemented.";
    throw std::runtime_error (oss.str ().c_str ());
  }
  else {
    CONSOLE_BRIDGE_logDebug ("Parsing robot urdf xml string");
    model = parseURDF(xml_string);
  }

  // copy data from model into this object
  if (model){
    this->links_ = model->links_;
    this->joints_ = model->joints_;
    this->materials_ = model->materials_;
    this->name_ = model->name_;
    this->root_link_ = model->root_link_;
    return true;
  }
  return false;
}
}// namespace
