/*!
 * \file map_reader.h
 * \brief Defines a class for reading and generating maps from properly-formatted
 * input files.
 *
 * \par Overview
 * This file can be used to provide all the necessary facilities to wrap up map
 * reading and generation of an internal representation.
 *
 * \author: Andres J. Tack
 */
#ifndef __MAP_READER_H__
#define __MAP_READER_H__

#include "map.hxx"
#include <iostream>

/*!
 * \brief Class for reading and generating maps from properly-formatted input.
 * 
 * You should never have to instantiate this class.  It only provides methods
 * which can be used to create and initialize other objects based on the given
 * input.
 */
class MapReader
{
public:
	/*!
	 * \brief Generates a Square Map object from the given input.
	 * 
	 * \param input is the input stream that will be converted into
	 * a Map object.
	 * 
	 * \return A pointer to an initialized square map.  NULL if there
	 * was an error.
	 */
	static Map* MakeMap(std::istream & input);
};

#endif
