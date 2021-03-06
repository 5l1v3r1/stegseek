/*
 * steghide 0.5.1 - a steganography program
 * Copyright (C) 1999-2003 Stefan Hetzl <shetzl@chello.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#ifndef SH_SMDCONSTRUCTIONHEURISTIC_H
#define SH_SMDCONSTRUCTIONHEURISTIC_H

#include "MatchingAlgorithm.h"
#include "Vertex.h"
#include "common.h"

/**
 * \class SMDConstructionHeuristic
 * \brief an implementation of the "static minimum degree" heuristic for contructing a matching
 **/
class SMDConstructionHeuristic : public MatchingAlgorithm {
	public:
	SMDConstructionHeuristic (Graph* g, Matching* m, float goal = 100.0) ;

	virtual ~SMDConstructionHeuristic (void) {} ;

	const char* getName (void) const
		{ return "Static Minimum Degree Construction Heuristic" ; } ;

	void run (void) ;

	private:
	class SmallerVertexDegree {
		public:
		bool operator() (const Vertex* v1, const Vertex* v2)
			{ return (v1->getDegree() < v2->getDegree()) ; } ;
	} ;

	std::vector<Vertex*> Vertices ;
} ;

#endif // ndef SH_SMDCONSTRUCTIONHEURISTIC_H
