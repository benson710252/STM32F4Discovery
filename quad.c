    #include<stdio.h>

    #include<stdlib.h>

    #include<math.h>


    int main()

    {

        float quadint( float, float, float );

        int i, j, k, m = 2;

        float dt = 0.1;

        float P = 0.13 ,Q = 0.25 ,R = 0.83;

        float de0 ,de1, de2 ,de3;

        float e0, e1, e2, e3;

        float phi2,psi2,theta2;

        float theta = 0.0, phi = 0.0, psi = 0.0;

        float Mx[3][3] = {{ 1, 0, 0}, { 0, cos(phi), sin(phi)}, { 0, -sin(phi), cos(phi)}};

        float My[3][3] = {{ cos(theta), 0, -sin(theta)}, { 0, 1, 0}, { sin(theta), 0, cos(theta)}};

        float Mz[3][3] = {{ cos(psi), sin(psi), 0}, { -sin(psi), cos(psi), 0}, {0, 0, 1}};

        float Mt[3][3], Mt_2[3][3];

        printf("Mx\n%f %f %f\n%f %f %f\n%f %f %f\n",Mx[0][0],Mx[0][1],Mx[0][2],Mx[1][0],Mx[1][1],Mx[1][2],Mx[2][0],Mx[2][1],Mx[2][2]);  

        printf("\n");

        printf("My\n%f %f %f\n%f %f %f\n%f %f %f\n",My[0][0],My[0][1],My[0][2],My[1][0],My[1][1],My[1][2],My[2][0],My[2][1],My[2][2]);  

        printf("\n");

        printf("Mz\n %f %f %f\n%f %f %f\n%f %f %f\n",Mz[0][0],Mz[0][1],Mz[0][2],Mz[1][0],Mz[1][1],Mz[1][2],Mz[2][0],Mz[2][1],Mz[2][2]);  

        printf("\n");

        for (i=0; i<=m; i++) {

            for (j=0; j<=m; j++) {

                Mt_2[i][j]=0; /*初始化陣列Mt_2 */

                for(k = 0; k <= m; k++) {

                    Mt_2[i][j] = Mt_2[i][j] +Mx[i][k] * My[k][j]; /*陣列A乘上陣列B,存入陣列C */

                                            }

                printf(" %f ", Mt_2[i][j]); /*輸出陣列Mt_2 */

                                           }

                printf("\n");

                         }

        printf("\n");

        for (i=0; i<=m; i++) {

            for (j=0; j<=m; j++) {

                Mt[i][j]=0; /*初始化陣列Mt */

                for(k = 0; k <= m; k++) {

                    Mt[i][j] = Mt[i][j] +Mt_2[i][k] * Mz[k][j]; /*陣列A乘上陣列B,存入陣列C */

                }

                printf(" %f ", Mt[i][j]); /*輸出陣列Mt */

            }

            printf("\n");

        }

        printf("\n");

        float E_ini[4][1] = { 

                  {0.5 * sqrt( 1.0 + Mt[0][0] + Mt[1][1] + Mt[2][2])}, 

                  {(Mt[1][2] - Mt[2][1] ) / ( 4.0 * 0.5 * sqrt( 1 + Mt[0][0] + Mt[1][1] + Mt[2][2] ))},

                  {(Mt[2][0] - Mt[0][2] ) / ( 4.0 * 0.5 * sqrt( 1 + Mt[0][0] + Mt[1][1] + Mt[2][2] ))},

                  {(Mt[0][1] - Mt[1][0] ) / ( 4.0 * 0.5 * sqrt( 1 + Mt[0][0] + Mt[1][1] + Mt[2][2] ))}

                             };

                  printf("E_ini\n%f\n%f\n%f\n%f\n",E_ini[0][0],E_ini[1][0],E_ini[2][0],E_ini[3][0]);

        e0 = E_ini[0][0];

        e1 = E_ini[1][0];

        e2 = E_ini[2][0];

        e3 = E_ini[3][0];                 

        de0 = 0.5 * ( -P * e1 - Q * e2 - R * e3 );

        de1 = 0.5 * (  P * e0 + R * e2 - Q * e3 );

        de2 = 0.5 * (  Q * e0 - R * e1 + P * e3 );

        de3 = 0.5 * (  R * e0 + Q * e1 - P * e2 );

        

        e0 = quadint( e0, de0, dt );

        e1 = quadint( e1, de1, dt );

        e2 = quadint( e2, de2, dt );

        e3 = quadint( e3, de3, dt );

        phi2 = atan( 2*( e0*e1 + e2*e3 ) / ( pow(e0,2) - pow(e1,2) - pow(e2,2) + pow(e3,2) ) ); 

        psi2 = atan( 2*( e0*e3 + e1*e2 ) / ( pow(e0,2) + pow(e1,2) - pow(e2,2) - pow(e3,2) ) );

        theta2 = asin( 2*( e0*e2 - e3*e1 ) );

        printf("phi2 = %f\npsi2 = %f\ntheta2 = %f\n",phi2,psi2,theta2);

        

        system("pause");

        return 0 ;

    }

    float quadint( float Initial, float Diffetential, float Timestep ) 

    {

      // The subfunction for Euler integration.

      return Initial + Diffetential * Timestep;

    }


