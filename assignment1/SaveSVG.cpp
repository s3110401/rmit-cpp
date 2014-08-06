/*
 * SaveSVG.cpp
 *
 *  Created on: 3 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

using namespace std;

void Maze::SaveSVG(char *fileName)
{
	ofstream svgFile(fileName, ofstream::out);
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' "
			"xmlns='http://www.w3.org/2000/svg'>\n"
			"<rect width='1' height='1' style='fill: black' />" << endl;

	for(int ip = 0; ip < this->numOfLInes  ; ip++)
	{
		/*
		 * We want to cast the x,y arrays to float
		 * before we divide by the width,height.
		 *
		 * Use float to reduce memory consumption
		 */
		svgFile << "<line stroke='white' stroke-width='0.005'"
				" x1='" << float(vectors[ip].x1)/width << "'"
				" y1='" << float(vectors[ip].y1)/height << "'"
				" x2='" << float(vectors[ip].x2)/width << "'"
				" y2='" << float(vectors[ip].y2)/height << "'/>" << endl;
	}

	svgFile << "</svg>" << flush;
	svgFile.close();

	cout << "Saving svg maze: " << fileName << endl;
}



// rand s.rand