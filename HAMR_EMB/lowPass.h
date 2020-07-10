// This code implements a simple first order low pass filter


#ifndef LOW_PASS_H
#define LOW_PASS_H
#include<math.h>

class lowPass{
    public: 

        lowPass(float cutoff_hz, float sample_hz):
            alpha(0.0f),
            filtered_data(0.0f),
            last_data(0.0f),
            w(0.0f),
            cutoff_hz_(cutoff_hz),
            sample_hz_(sample_hz)
        {update_alpha();};       

        float filter(float input_data){
            filtered_data = alpha*input_data + (1-alpha)*last_data;
            last_data = filtered_data;
            return filtered_data;
        };
    
    protected:
        float alpha;
        float filtered_data;
        float last_data;
        float w;

    private:
        float cutoff_hz_;
        float sample_hz_;
        void update_alpha(){
            w = 2*PI*cutoff_hz_/sample_hz_;
            alpha  = cos(w) - 1 + sqrt(cos(w)*cos(w) - 4*cos(w) + 3);
        };       
    };
    
#endif