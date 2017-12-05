# glEnable(GL_NORMALIZE)的作用

glEnable(GL_NORMALIZE)是使opengl自动normalize 法向量，之所以需要自动normalize 法向量是因为法向量会受到glScalef的影响，当glScalef将物体的坐标放大k倍时，法向量变为1/k，具体的原因可参见： http://www.videotutorialsrock.com/opengl_tutorial/normalize/text.php 

因为opengl自己的光照计算要求法向量单位化，所以不重新单位化，计算结果就是错误的。因此，可以使用glEnable(GL_NORMALIZE), opengl在进行光照计算之前会自动单位化法向量。但这样方便了光照计算的同时也降低了程序的性能，因为每次所有的法向量都要重新单位化。