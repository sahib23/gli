///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/texture_cube.hpp
/// @date 2011-04-06 / 2013-01-11
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_TEXTURE_CUBE_INCLUDED
#define GLI_CORE_TEXTURE_CUBE_INCLUDED

#include "texture2d.hpp"

namespace gli
{
	class textureCube
	{
	public:
		typedef storage::dimensions2_type dimensions_type;
		typedef storage::texcoord3_type texcoord_type;
		typedef storage::size_type size_type;
		typedef storage::format_type format_type;

	public:
		textureCube();

		/// Allocate a new storage constructor
		explicit textureCube(
			size_type const & Faces,
			size_type const & Levels,
			format_type const & Format,
			dimensions_type const & Dimensions);

		/// Reference an exiting storage constructor
		explicit textureCube(
			storage const & Storage);

		/// Reference a subset of an exiting storage constructor
		explicit textureCube(
			storage const & Storage,
			format_type const & Format,
			view const & View);

		/// Create a texture view, reference a subset of an exiting storage
		explicit textureCube(
			textureCube const & Texture,
			size_type const & BaseFace,
			size_type const & MaxFace,
			size_type const & BaseLevel,
			size_type const & MaxLevel);

		operator storage() const;
		texture2D operator[] (size_type const & Face) const;

		bool empty() const;
		format_type format() const;
		dimensions_type dimensions() const;
		size_type layers() const;
		size_type faces() const;
		size_type levels() const;
		view const & view() const;

		size_type size() const;
		void * data();
		void const * data() const;

		template <typename genType>
		size_type size() const;
		template <typename genType>
		genType * data();
		template <typename genType>
		genType const * data() const;

	private:
		storage Storage;
		gli::view View;
		format_type Format;
	};
}//namespace gli

#include "texture_cube.inl"

#endif//GLI_CORE_TEXTURE_CUBE_INCLUDED
