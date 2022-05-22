/*
 * This is a C-to-JS conversion of the trackball implementation by
 * Gavin Ball of Silicon Graphics.
 */
/*
 * (c) Copyright 1993, 1994, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(TM) is a trademark of Silicon Graphics, Inc.
 */
/*
 * Trackball code:
 *
 * Implementation of a virtual trackball.
 * Implemented by Gavin Bell, lots of ideas from Thant Tessman and
 *   the August '88 issue of Siggraph's "Computer Graphics," pp. 121-129.
 *
 * Vector manip code:
 *
 * Original code from:
 * David M. Ciemiewicz, Mark Grossman, Henry Moreton, and Paul Haeberli
 *
 * Much mucking with by:
 * Gavin Bell
 */

(function(trackball) {
    "use strict";

    /*
     * This size should really be based on the distance from the center of
     * rotation to the point on the object underneath the mouse.  That
     * point would then track the mouse as closely as possible.  This is a
     * simple example, though, so that is left as an Exercise for the
     * Programmer.
     */
    var TRACKBALLSIZE = 0.5;

    /* Require twgl library */
    var v3 = twgl.v3;
    var m4 = twgl.m4;

    /*
     * Ok, simulate a track-ball.  Project the points onto the virtual
     * trackball, then figure out the axis of rotation, which is the cross
     * product of P1 P2 and O P1 (O is the center of the ball, 0,0,0)
     * Note:  This is a deformed trackball-- is a trackball in the center,
     * but is deformed into a hyperbolic sheet of rotation away from the
     * center.  This particular function was chosen after trying out
     * several variations.
     *
     * It is assumed that the arguments to this routine are in the range
     * (-1.0 ... 1.0)
     */
    trackball.create = function(p1x, p1y, p2x, p2y) {
        var axis = [0, 0, 0];
        var phi;
        var p1, p2, d;
        var t;

        if (p1x == p2x && p1y == p2y) {
            /* Zero rotation */
            return [0, 0, 0, 1];
        }

        /*
         * First, figure out z-coordinates for projection of P1 and P2 to
         * deformed sphere
         */
        p1 = [p1x, p1y, projectToSphere(TRACKBALLSIZE, p1x, p1y)];
        p2 = [p2x, p2y, projectToSphere(TRACKBALLSIZE, p2x, p2y)];

        /*
         *  Now, we want the cross product of P1 and P2
         */
        axis = v3.cross(p2, p1);

        /*
         *  Figure out how much to rotate around that axis.
         */
        d = v3.subtract(p1, p2);
        t = v3.length(d) / (2.0 * TRACKBALLSIZE);

        /*
         * Avoid problems with out-of-control values...
         */
        if (t > 1.0) t = 1.0;
        if (t < -1.0) t = -1.0;
        phi = 2.0 * Math.asin(t);

        return axisToQuat(axis, phi);
    }

    /*
     *  Given an axis and angle, compute quaternion.
     */
    function axisToQuat(axis, phi) {
        var q = v3.copy(axis);
        q = v3.normalize(q);
        q = v3.mulScalar(q, Math.sin(phi/2.0));
        return [q[0], q[1], q[2], Math.cos(phi/2.0)];
    }

    /*
     * Project an x,y pair onto a sphere of radius r OR a hyperbolic sheet
     * if we are away from the center of the sphere.
     */
    function projectToSphere(r, x, y) {
        var d, t, z;

        d = Math.sqrt(x*x + y*y);
        if (d < r * 0.70710678118654752440) {    /* Inside sphere */
            z = Math.sqrt(r*r - d*d);
        } else {           /* On hyperbola */
            t = r / 1.41421356237309504880;
            z = t*t / d;
        }
        return z;
    }

    /*
     * Given two rotations, e1 and e2, expressed as quaternion rotations,
     * figure out the equivalent single rotation and stuff it into dest.
     *
     * This routine also normalizes the result every RENORMCOUNT times it is
     * called, to keep error from creeping in.
     *
     * NOTE: This routine is written so that q1 or q2 may be the same
     * as dest (or each other).
     */

    var RENORMCOUNT = 97;
    var count = 0;

    trackball.addQuats = function (q1, q2) {
        var t1, t2, t3;
        var tf;

        t1 = v3.copy(q1);
        t1 = v3.mulScalar(t1, q2[3]);

        t2 = v3.copy(q2);
        t2 = v3.mulScalar(t2, q1[3]);

        t3 = v3.cross(q2, q1);
        tf = v3.add(t1, t2);
        tf = v3.add(t3, tf);

        var quat = [tf[0], tf[1], tf[2], q1[3] * q2[3] - v3.dot(q1, q2)] 
        if (++count > RENORMCOUNT) {
            count = 0;
            quat = normalizeQuat(quat);
        }
        return quat;
    }

    /*
     * Quaternions always obey:  a^2 + b^2 + c^2 + d^2 = 1.0
     * If they don't add up to 1.0, dividing by their magnitued will
     * renormalize them.
     *
     * Note: See the following for more information on quaternions:
     *
     * - Shoemake, K., Animating rotation with quaternion curves, Computer
     *   Graphics 19, No 3 (Proc. SIGGRAPH'85), 245-254, 1985.
     * - Pletinckx, D., Quaternion calculus as a basic tool in computer
     *   graphics, The Visual Computer 5, 2-13, 1989.
     */
    function normalizeQuat(q) {
        var i;
        var mag;
        var quat = [];

        mag = Math.sqrt(q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3]);
        for (i = 0; i < 4; i++) quat[i] = q[i] / mag;

        return quat;
    }

    /*
     * Build a rotation matrix, given a quaternion rotation.
     *
     */
    trackball.buildMatrix = function(q) {
        var m = [];

        m[0] = 1.0 - 2.0 * (q[1] * q[1] + q[2] * q[2]);
        m[1] = 2.0 * (q[0] * q[1] - q[2] * q[3]);
        m[2] = 2.0 * (q[2] * q[0] + q[1] * q[3]);
        m[3] = 0.0;

        m[4] = 2.0 * (q[0] * q[1] + q[2] * q[3]);
        m[5]= 1.0 - 2.0 * (q[2] * q[2] + q[0] * q[0]);
        m[6] = 2.0 * (q[1] * q[2] - q[0] * q[3]);
        m[7] = 0.0;

        m[8] = 2.0 * (q[2] * q[0] - q[1] * q[3]);
        m[9] = 2.0 * (q[1] * q[2] + q[0] * q[3]);
        m[10] = 1.0 - 2.0 * (q[1] * q[1] + q[0] * q[0]);
        m[11] = 0.0;

        m[12] = 0.0;
        m[13] = 0.0;
        m[14] = 0.0;
        m[15] = 1.0;

        return m;
    }
 
}(window.trackball = window.trackball || {}));
