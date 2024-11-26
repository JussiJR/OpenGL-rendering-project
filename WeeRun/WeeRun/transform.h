﻿/**
*  _____                                                                                                _____
* ( ___ )                                                                                              ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ############################################################################################## |   |
*  |   | ##████████╗██████╗##█████╗#███╗###██╗███████╗███████╗#██████╗#██████╗#███╗###███╗###██╗##██╗## |   |
*  |   | ##╚══██╔══╝██╔══██╗██╔══██╗████╗##██║██╔════╝██╔════╝██╔═══██╗██╔══██╗████╗#████║###██║##██║## |   |
*  |   | #####██║###██████╔╝███████║██╔██╗#██║███████╗█████╗##██║###██║██████╔╝██╔████╔██║###███████║## |   |
*  |   | #####██║###██╔══██╗██╔══██║██║╚██╗██║╚════██║██╔══╝##██║###██║██╔══██╗██║╚██╔╝██║###██╔══██║## |   |
*  |   | #####██║###██║##██║██║##██║██║#╚████║███████║██║#####╚██████╔╝██║##██║██║#╚═╝#██║██╗██║##██║## |   |
*  |   | #####╚═╝###╚═╝##╚═╝╚═╝##╚═╝╚═╝##╚═══╝╚══════╝╚═╝######╚═════╝#╚═╝##╚═╝╚═╝#####╚═╝╚═╝╚═╝##╚═╝## |   |
*  |   | ############################################################################################## |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                                                                              (_____)
* 
* 
* SUMMARY:
*
* KNOWN ISSUES:
*
* STRUCTURES:
*	- Transform
*		# Definition:
*			Used with object's position representation
*		# Knowwn issues:
*			NoN
*		# Note
*			Propably most complicated and optimized part of the whole project.
*			And definetly most significantly complex struct since had to invent IEE Single precision floating point value again.
* 
* 
* METHODS:
*	- Transform : CreateTransform (int, int)
*		# Definition:
*			## Summary:
*				Constructor method to create Transform and set default position
*			## Parameters:
*				- int WorldX  : Entity's world position's X
*				- int WorldY : Entity's world position's Y
*			## Known Issues:
*				- NoN
*			## Note: 
*				
*
* USED REFERENCES:
*	- https://en.wikipedia.org/wiki/Scientific_notation -Wikipedia page of Scientific notation
*	- https://en.wikipedia.org/wiki/Single-precision_floating-point_format - IEE Single precsion floating point number Wikipedia page
*	- https://en.wikipedia.org/wiki/Half-precision_floating-point_format - Half precision floating point number
*	- https://gcc.gnu.org/onlinedocs/gcc/Half-Precision.html - GCC page about halfs
*	- https://en.wikipedia.org/wiki/Floating-point_arithmetic - float arithmics
*	- https://en.wikipedia.org/wiki/Binary_number - base two system
*	- https://en.wikipedia.org/wiki/Matrix_(mathematics) - Matrix Wikipedia
*	- https://www.youtube.com/watch?v=p48uw2vFWQs - matrix maths
*	- https://en.wikipedia.org/wiki/Transformation_matrix - Transform matri
*	- https://www.geeksforgeeks.org/calling-conventions-in-c-cpp/ - Calling Conversions
*/

#ifndef _transform_h_

#pragma once
#pragma pack(1)

//!NOTE: Defines

//!	Header Lock
#define _transform_h_

//!	Vector
//!		MinMax values
#define VECTOR_POINT_MAX_VALUE 15 
#define VECTOR_POINT_MIN_VALUE 0

//!	Decimal normalization
//!		MinMax values
#define NORMAL_DECIMAL_MIN_VALUE 
#define NORMAL_DECIMAL_MAX_VALUE 



//!NOTE: Includes

#ifndef _STDINT
#include <stdint.h>
#endif

#ifndef __gamemanager_h__
#include "GameManager.h"
#endif // !__gamemanager_h__

//!NOTE: Typedefs

/*
* NAME: Transform
* SUMMARY:
*	Represents object's position in world space
*/
typedef struct Transform {


	//	Distance (0.000... - 1.000000...)
	uint_fast64_t DistanceDecimal : 19;

	//	Correction decimal (0.000... - 1.000000...)
	uint_fast64_t CorrectionDecimal : 19;

	//	Current chunk
	uint_fast64_t VectorPointA : 6;
	uint_fast64_t VectorPointB : 6;
	uint_fast64_t CorrectionPoint : 6;
} Transform;

//!NOTE: Methods

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for Transform multiplications
* PRAMATERS:
*	- Transform* target : object to be multiplied
*	- Transform* mult : object to be multiplied with
* RETURNS:
*	Result of a multiplication
*/
Transform TransformxTransform(Transform* target, Transform* mult,GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  multiplications between floats and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformxFloat(Transform* target, float mult, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  multiplications between integers and Transforms
* PRAMATERS:
*	- Transform* target : object to be multiplied 
*	- int mult : float to be multiplied with
* RETURNS:
*	Result of a multiplication
*/
Transform TransformxInt(Transform* target, int mult, GameManager* manager, unsigned char currentChunk);



/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  multiplications between Transform and Transforms
*	Note: it also assigns values to target
* PRAMATERS:
*	- Transform* target : object to be multiplied
*	- Transform* mult : Transform to be multiplied with
*/
void TransformxTransformSelf(Transform* target, Transform* mult, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  multiplications between floats and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformxFloatSelf(Transform* target, float mult, GameManager* manager, unsigned char currentChunk);


/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  multiplications between floats and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformxIntSelf(Transform* target, int mult, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformdTransform(Transform* target, Transform* div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformdFloat(Transform* target, float div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform Transformdint(Transform* target, int div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformdTransformSelf(Transform* target, Transform* div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformdFloatSelf(Transform* target, float div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformdIntSelf(Transform* target, int div, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformsTransform(Transform* targert, Transform* sub, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformsFloat(Transform* targert, float sub, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformsInt(Transform* targert, int sub, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformsTransformSelf(Transform* targert, Transform* sub, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformsFloatSelf(Transform* targert, float sub, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformsIntSelf(Transform* targert, int sub, GameManager* manager, unsigned char currentChunk);



/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformaTransform(Transform* targert, Transform* add, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformaFloat(Transform* targert, float add, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
Transform TransformaInt(Transform* targert, int add, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformaTransformSelf(Transform* targert, Transform* add, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformaFloatSelf(Transform* targert, float add, GameManager* manager, unsigned char currentChunk);

/*
* NAME: TransformxTransform
* SUMMARY:
*	Used for  divide between Transforms and Transforms
* PRAMATERS:
*	- Transform* target : object to be added into
*	- float mult : float to be added
* RETURNS:
*	Result of a multiplication
*/
void TransformaIntSelf(Transform* targert, int add, GameManager* manager, unsigned char currentChunk);


/*
* NAME: TransformExport
* SUMMARY:
*	Used for  Exporting object for vertex shader to use
* PRAMATERS:
*	- Transform* target : target object
* RETURNS:
*	Result of a packing
*/
long long TransformExport(Transform* target, GameManager* manager, unsigned char currentChunk);



#pragma pack(pop)
#endif