// // // #include <CL/cl.h>
// // // #include <iostream>
// // // #include <vector>
// // // #include <cstring>

// // // // Простая функция проверки ошибок
// // // #define CHECK_ERROR(err, msg) \
// // //     if (err != CL_SUCCESS) { \
// // //         std::cerr << "Error OpenCL: " << msg << " (code: " << err << ")" << std::endl; \
// // //         return -1; \
// // //     }

// // // // Ядро OpenCL C для сложения массивов
// // // const char* kernelSource = R"(
// // // __kernel void vector_add(__global const int* a,
// // //                          __global const int* b,
// // //                          __global int* c,
// // //                          const int n) {
// // //     int i = get_global_id(0);
// // //     if (i < n) {
// // //         c[i] = a[i] + b[i];
// // //     }
// // // }
// // // )";

// // // int main() {
// // //     // Размер массивов
// // //     const int N = 100;
// // //     std::vector<int> a(N), b(N), c(N, 0);
    
// // //     // Инициализация входных данных
// // //     for (int i = 0; i < N; i++) {
// // //         a[i] = i;
// // //         b[i] = i * 2;
// // //     }
    
// // //     std::cout << "In:" << std::endl;
// // //     for (int i = 0; i < N; i++) {
// // //         std::cout << "a[" << i << "] = " << a[i] 
// // //                   << ", b[" << i << "] = " << b[i] << std::endl;
// // //     }
    
// // //     cl_int err;
    
// // //     // 1. Получаем доступные платформы
// // //     cl_uint numPlatforms;
// // //     err = clGetPlatformIDs(0, nullptr, &numPlatforms);
// // //     CHECK_ERROR(err, "clGetPlatformIDs (count)");
    
// // //     if (numPlatforms == 0) {
// // //         std::cerr << "OpenCL not installed" << std::endl;
// // //         return -1;
// // //     }
    
// // //     std::vector<cl_platform_id> platforms(numPlatforms);
// // //     err = clGetPlatformIDs(numPlatforms, platforms.data(), nullptr);
// // //     CHECK_ERROR(err, "clGetPlatformIDs (got list)");
    
// // //     // 2. Выбираем первую платформу и получаем GPU устройство
// // //     cl_device_id device;
// // //     err = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_GPU, 1, &device, nullptr);
// // //     if (err != CL_SUCCESS) {
// // //         // Если GPU нет, пробуем CPU
// // //         err = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_CPU, 1, &device, nullptr);
// // //         CHECK_ERROR(err, "clGetDeviceIDs (not GPU, not CPU)");
// // //         std::cout << "Using CPU" << std::endl;
// // //     } else {
// // //         std::cout << "Using GPU" << std::endl;
// // //     }
    
// // //     // 3. Создаём контекст
// // //     cl_context context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &err);
// // //     CHECK_ERROR(err, "clCreateContext");
    
// // //     // 4. Создаём очередь команд
// // //     cl_command_queue queue = clCreateCommandQueue(context, device, 0, &err);
// // //     CHECK_ERROR(err, "clCreateCommandQueue");
    
// // //     // 5. Создаём буферы для данных
// // //     cl_mem bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
// // //                                     N * sizeof(int), a.data(), &err);
// // //     CHECK_ERROR(err, "clCreateBuffer (A)");
    
// // //     cl_mem bufferB = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
// // //                                     N * sizeof(int), b.data(), &err);
// // //     CHECK_ERROR(err, "clCreateBuffer (B)");
    
// // //     cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
// // //                                     N * sizeof(int), nullptr, &err);
// // //     CHECK_ERROR(err, "clCreateBuffer (C)");
    
// // //     // 6. Создаём программу из исходного кода
// // //     cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, nullptr, &err);
// // //     CHECK_ERROR(err, "clCreateProgramWithSource");
    
// // //     // 7. Компилируем программу
// // //     err = clBuildProgram(program, 1, &device, nullptr, nullptr, nullptr);
// // //     if (err != CL_SUCCESS) {
// // //         // Выводим лог компиляции в случае ошибки
// // //         size_t logSize;
// // //         clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, nullptr, &logSize);
// // //         std::vector<char> log(logSize);
// // //         clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, logSize, log.data(), nullptr);
// // //         std::cerr << "Kernel not works:" << std::endl << log.data() << std::endl;
// // //         return -1;
// // //     }
    
// // //     // 8. Создаём ядро
// // //     cl_kernel kernel = clCreateKernel(program, "vector_add", &err);
// // //     CHECK_ERROR(err, "clCreateKernel");
    
// // //     // 9. Устанавливаем аргументы ядра
// // //     err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
// // //     err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferB);
// // //     err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &bufferC);
// // //     err |= clSetKernelArg(kernel, 3, sizeof(int), &N);
// // //     CHECK_ERROR(err, "clSetKernelArg");
    
// // //     // 10. Запускаем ядро
// // //     size_t globalSize = N;
// // //     err = clEnqueueNDRangeKernel(queue, kernel, 1, nullptr, &globalSize, nullptr, 0, nullptr, nullptr);
// // //     CHECK_ERROR(err, "clEnqueueNDRangeKernel");
    
// // //     // 11. Читаем результат
// // //     err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, N * sizeof(int), c.data(), 0, nullptr, nullptr);
// // //     CHECK_ERROR(err, "clEnqueueReadBuffer");
    
// // //     // 12. Выводим результат
// // //     std::cout << "\nResult:" << std::endl;
// // //     for (int i = 0; i < N; i++) {
// // //         std::cout << "c[" << i << "] = " << a[i] << " + " << b[i] << " = " << c[i] << std::endl;
// // //     }
    
// // //     // 13. Освобождаем ресурсы
// // //     clReleaseKernel(kernel);
// // //     clReleaseProgram(program);
// // //     clReleaseMemObject(bufferA);
// // //     clReleaseMemObject(bufferB);
// // //     clReleaseMemObject(bufferC);
// // //     clReleaseCommandQueue(queue);
// // //     clReleaseContext(context);
    
// // //     return 0;
// // // }