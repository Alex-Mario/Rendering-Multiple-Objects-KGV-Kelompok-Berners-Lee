#define _USE_MATH_DEFINES                                                                                  
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Util.h"
#include <math.h>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"


int main(int key, int scancode, int action, int mods) //main program                                        
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "OOP Rendering Multiple Objects KGV Kelompok Berners Lee", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();

    Square s1; // kotak depan1
    s1.setTranslation(-0.6f, 0.2f, 0.0f);
    s1.setScale(glm::vec3(0.25f, 0.3f, 1.0f));
    s1.setColor(glm::vec4(0.827f, 0.584f, 0.192f, 1.0f));

   Square s2; // kotak depan2
    s2.setTranslation(glm::vec3(-0.65f, 0.25f, 0.0f));
    s2.setScale(glm::vec3(0.20f, 0.15f, 1.0f));
    s2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s3; // kotak belakang
    s3.setTranslation(glm::vec3(0.15f, 0.25f, 0.0f));
    s3.setScale(glm::vec3(0.5f, 0.35f, 1.0f));
    s3.setColor(glm::vec4(0.831f, 0.109f, 0.149f, 1.0f));
   
    Square s4; //ban1
    s4.setTranslation(glm::vec3(-0.6f, -0.15f, 0.0f));
    s4.setScale(glm::vec3(0.1f, 0.115f, 1.0f));
    s4.setColor(glm::vec4(0.368f, 0.368f, 0.368f, 1.0f));

    Square s12; //isiban1
    s12.setTranslation(glm::vec3(-0.6f, -0.15f, 0.0f));
    s12.setScale(glm::vec3(0.03f, 0.03f, 1.0f));
    s12.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    
    Square s5; //ban2
    s5.setTranslation(glm::vec3(-0.1f, -0.15f, 0.0f));
    s5.setScale(glm::vec3(0.1f, 0.115f, 1.0f));
    s5.setColor(glm::vec4(0.368f, 0.368f, 0.368f, 1.0f));

    Square s13; //isiban2
    s13.setTranslation(glm::vec3(-0.1f, -0.15f, 0.0f));
    s13.setScale(glm::vec3(0.03f, 0.03f, 1.0f));
    s13.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s6; //ban3
    s6.setTranslation(glm::vec3(0.4f, -0.15f, 0.0f));
    s6.setScale(glm::vec3(0.1f, 0.115f, 1.0f));
    s6.setColor(glm::vec4(0.368f, 0.368f, 0.368f, 1.0f));

    Square s14; //isiban3
    s14.setTranslation(glm::vec3(0.4f, -0.15f, 0.0f));
    s14.setScale(glm::vec3(0.03f, 0.03f, 1.0f));
    s14.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    
    Square s7; //knalpot
    s7.setTranslation(glm::vec3(0.69f, 0.07f, 0.0f));
    s7.setScale(glm::vec3(0.04f, 0.03f, 1.0f));
    s7.setColor(glm::vec4(0.925f, 0.607f, 0.494f, 1.0f));
    
    Square s8; //asap1
    s8.setRotation(45.0f, glm::vec3(1.0f, 0.00f, 1.0f));
    s8.setTranslation(glm::vec3(0.6f, -0.55f, 0.0f));
    s8.setScale(glm::vec3(0.018f, 0.018f, 1.0f));
    s8.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s9; //asap2
    s9.setRotation(45.0f, glm::vec3(1.0f, 0.00f, 1.0f));
    s9.setTranslation(glm::vec3(0.66f, -0.6f, 0.0f));
    s9.setScale(glm::vec3(0.023f, 0.023f, 1.0f));
    s9.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s10; //asap3
    s10.setRotation(45.0f, glm::vec3(1.0f, 0.00f, 1.0f));
    s10.setTranslation(glm::vec3(0.72f, -0.65f, 0.0f));
    s10.setScale(glm::vec3(0.03f, 0.03f, 1.0f));
    s10.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s11; //aspal
    s11.setScale(glm::vec3(1.0f, 0.5f, 1.0f));
    s11.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    /* Loop until the user closes the window */                                                          
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.745f, 0.803f, 0.901f, 1.0f); // warna window biru langit

        glUseProgram(program);

        //glDrawArrays(GL_TRIANGLES,0,6);

        glUniform4fv(uColor, 1, &s11.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s11.getTransformationMat4x4()[0][0]);
        s11.draw();

        glUniform4fv(uColor, 1, &s1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s1.getTransformationMat4x4()[0][0]);
        s1.draw();

        glUniform4fv(uColor, 1, &s2.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s2.getTransformationMat4x4()[0][0]);
        s2.draw();
       
        glUniform4fv(uColor, 1, &s3.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s3.getTransformationMat4x4()[0][0]);
        s3.draw();
        
        glUniform4fv(uColor, 1, &s4.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s4.getTransformationMat4x4()[0][0]);
        s4.draw();
        
        glUniform4fv(uColor, 1, &s5.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s5.getTransformationMat4x4()[0][0]);
        s5.draw();

        glUniform4fv(uColor, 1, &s6.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s6.getTransformationMat4x4()[0][0]);
        s6.draw();
        
        glUniform4fv(uColor, 1, &s7.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s7.getTransformationMat4x4()[0][0]);
        s7.draw();
        
        glUniform4fv(uColor, 1, &s8.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s8.getTransformationMat4x4()[0][0]);
        s8.draw();

        glUniform4fv(uColor, 1, &s9.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s9.getTransformationMat4x4()[0][0]);
        s9.draw();

        glUniform4fv(uColor, 1, &s10.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s10.getTransformationMat4x4()[0][0]);
        s10.draw();

        glUniform4fv(uColor, 1, &s12.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s12.getTransformationMat4x4()[0][0]);
        s12.draw();

        glUniform4fv(uColor, 1, &s13.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s13.getTransformationMat4x4()[0][0]);
        s13.draw();

        glUniform4fv(uColor, 1, &s14.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s14.getTransformationMat4x4()[0][0]);
        s14.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}
