function(changeLibOmpDylib target application)
  message(STATUS "adding post-build libomp install_name_tool change command for target ${target} and application ${application}") 
  changeDylib(${target} ${application} libomp.dylib /usr/local/opt/libomp/lib)
  
endfunction()

macro(changeDylib target application libname libpath)
  add_custom_command(TARGET ${target} POST_BUILD
  COMMAND 
  install_name_tool -change \"${libpath}/${libname}\" \"@executable_path/../../Frameworks/${libname}\" \"${CMAKE_BINARY_DIR}/${application}\"

  COMMENT "Change ${libname} dylib path ${application}"
  )
endmacro()
