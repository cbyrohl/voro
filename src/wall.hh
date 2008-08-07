// Voro++, a 3D cell-based Voronoi library
//
// Author   : Chris H. Rycroft (LBL / UC Berkeley)
// Email    : chr@alum.mit.edu
// Date     : July 1st 2008

#ifndef VOROPP_WALL_HH
#define VOROPP_WALL_HH

/** This class represents a spherical wall object. */
struct wall_sphere : public wall {
	public:
		/** Constructs a spherical wall object.
		 * \param[in] (ixc,iyc,izc) a position vector for the sphere's
		 * center.
		 * \param[in] irc the radius of the sphere. */
		wall_sphere(fpoint ixc,fpoint iyc,fpoint izc,fpoint irc)
			: w_id(-99), xc(ixc), yc(iyc), zc(izc), rc(irc) {};
		/** Constructs a spherical wall object.
		 * \param[in] iw_id an ID number to associate with the wall for
		 * neighbor tracking. 
		 * \param[in] (ixc,iyc,izc) a position vector for the sphere's
		 * center.
		 * \param[in] irc the radius of the sphere. */
		wall_sphere(int iw_id,fpoint ixc,fpoint iyc,fpoint izc,fpoint irc)
			: w_id(iw_id), xc(ixc), yc(iyc), zc(izc), rc(irc) {};
		bool point_inside(fpoint x,fpoint y,fpoint z);
		template<class n_option>
		inline bool cut_cell_base(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z);
		bool cut_cell(voronoicell_base<neighbor_none> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
		bool cut_cell(voronoicell_base<neighbor_track> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
	private:
		const int w_id;
		const fpoint xc,yc,zc,rc;
};

/** This class represents a single plane wall object. */
struct wall_plane : public wall {
	public:
		/** Constructs a plane wall object
		 * \param[in] (ixc,iyc,izc) a normal vector to the plane.
		 * \param[in] iac a displacement along the normal vector. */
		wall_plane(fpoint ixc,fpoint iyc,fpoint izc,fpoint iac)
			: w_id(-99), xc(ixc), yc(iyc), zc(izc), ac(iac) {};
		/** Constructs a plane wall object
		 * \param[in] iw_id an ID number to associate with the wall for
		 * neighbor tracking. 
		 * \param[in] (ixc,iyc,izc) a normal vector to the plane.
		 * \param[in] iac a displacement along the normal vector. */
		wall_plane(int iw_id,fpoint ixc,fpoint iyc,fpoint izc,fpoint iac)
			: w_id(iw_id), xc(ixc), yc(iyc), zc(izc), ac(iac) {};
		bool point_inside(fpoint x,fpoint y,fpoint z);
		template<class n_option>
		inline bool cut_cell_base(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z);
		bool cut_cell(voronoicell_base<neighbor_none> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
		bool cut_cell(voronoicell_base<neighbor_track> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
	private:
		const int w_id; 
		const fpoint xc,yc,zc,ac;
};

/** This class respresents a open cylinder wall object. */
struct wall_cylinder : public wall {
	public:
		/** Constructs a cylinder wall object.
		 * \param[in] (ixc,iyc,izc) a point on the axis of the
		 * cylinder.
		 * \param[in] (ixa,iya,iza) a vector pointing along the
		 * direction of the cylinder.
		 * \param[in] irc the radius of the cylinder */
		wall_cylinder(fpoint ixc,fpoint iyc,fpoint izc,fpoint ixa,fpoint iya,fpoint iza,fpoint irc)
			: w_id(-99), xc(ixc), yc(iyc), zc(izc), xa(ixa), ya(iya), za(iza),
			asi(1/(ixa*ixa+iya*iya+iza*iza)), rc(irc) {};
		/** Constructs a cylinder wall object.
		 * \param[in] iw_id an ID number to associate with the wall for
		 * neighbor tracking. 
		 * \param[in] (ixc,iyc,izc) a point on the axis of the
		 * cylinder.
		 * \param[in] (ixa,iya,iza) a vector pointing along the
		 * direction of the cylinder.
		 * \param[in] irc the radius of the cylinder */
		wall_cylinder(int iw_id,fpoint ixc,fpoint iyc,fpoint izc,fpoint ixa,fpoint iya,fpoint iza,fpoint irc)
			: w_id(iw_id), xc(ixc), yc(iyc), zc(izc), xa(ixa), ya(iya), za(iza),
			asi(1/(ixa*ixa+iya*iya+iza*iza)), rc(irc) {};
		bool point_inside(fpoint x,fpoint y,fpoint z);
		template<class n_option>
		inline bool cut_cell_base(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z);
		bool cut_cell(voronoicell_base<neighbor_none> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
		bool cut_cell(voronoicell_base<neighbor_track> &c,fpoint x,fpoint y,fpoint z) {return cut_cell_base(c,x,y,z);}
	private:
		const int w_id;
		const fpoint xc,yc,zc,xa,ya,za,asi,rc;
};

#endif
