# Fichero makefile del proyecto	
HOME = .
SRC=$(HOME)/src
LIB=$(HOME)/lib
INCLUDE=$(HOME)/include
OBJ=$(HOME)/obj
BIN=$(HOME)/bin





all : $(BIN)/potencial_docente 
	@echo Todos los objetos y ejecutables creados.

$(BIN)/potencial_docente: $(OBJ)/potencial_docente.o $(LIB)/libClaseDepart.a \
                          $(LIB)/libClaseProf.a $(LIB)/libClaseEncar.a \
                          $(LIB)/libClaseAdscrip.a $(LIB)/libutils.a\
                          $(LIB)/libClaseFecha.a \
                          $(LIB)/libVectorDepartamento.a\
                          $(LIB)/libVectorProfesor.a\
                          $(LIB)/libVectorAdscripcion.a\
                          $(LIB)/libVectorEncargo.a                             
	
	g++ -o $(BIN)/potencial_docente $(OBJ)/potencial_docente.o \
	       -L./lib -lClaseProf -lClaseDepart \
	       -lClaseEncar -lClaseAdscrip -lutils -lVectorDepartamento\
	       -lVectorProfesor -lVectorAdscripcion -lVectorEncargo -lClaseFecha

$(OBJ)/potencial_docente.o : $(SRC)/potencial_docente.cpp \
                             $(INCLUDE)/Departamento.h \
                             $(INCLUDE)/Profesor.h $(INCLUDE)/Encargos.h \
                             $(INCLUDE)/Adscripcion.h $(INCLUDE)/utils.h \
                             $(INCLUDE)/Fecha.h
	
	g++ -c -o $(OBJ)/potencial_docente.o \
	          $(SRC)/potencial_docente.cpp -I./include -std=c++14


	
$(LIB)/libClaseDepart.a :  $(OBJ)/ClaseDepart.o $(OBJ)/utils.o             
	
	ar -rvs $(LIB)/libClaseDepart.a $(OBJ)/ClaseDepart.o $(OBJ)/utils.o

$(OBJ)/ClaseDepart.o: $(SRC)/Departamento.cpp $(INCLUDE)/utils.h \
                      $(INCLUDE)/Departamento.h
	
	g++ -c -o $(OBJ)/ClaseDepart.o $(SRC)/Departamento.cpp -I./include \
	          -std=c++14	

$(LIB)/libClaseProf.a :  $(OBJ)/ClaseProf.o $(OBJ)/utils.o $(OBJ)/ClaseFecha.o            
	
	ar -rvs $(LIB)/libClaseProf.a $(OBJ)/ClaseProf.o $(OBJ)/utils.o \
	        $(OBJ)/ClaseFecha.o

$(OBJ)/ClaseProf.o: $(SRC)/Profesor.cpp $(INCLUDE)/utils.h \
                    $(INCLUDE)/Fecha.h $(INCLUDE)/Profesor.h
	
	g++ -c -o $(OBJ)/ClaseProf.o $(SRC)/Profesor.cpp -I./include -std=c++14
	
$(LIB)/libClaseFecha.a :  $(OBJ)/ClaseFecha.o $(OBJ)/utils.o             
	
	ar -rvs $(LIB)/libClaseFecha.a $(OBJ)/ClaseFecha.o $(OBJ)/utils.o 

$(OBJ)/ClaseFecha.o: $(SRC)/Fecha.cpp $(INCLUDE)/utils.h \
                     $(INCLUDE)/Fecha.h
	
	g++ -c -o $(OBJ)/ClaseFecha.o $(SRC)/Fecha.cpp -I./include\
	          -std=c++14

$(LIB)/libutils.a : $(OBJ)/utils.o             
	
	ar -rvs $(LIB)/libutils.a $(OBJ)/utils.o 

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INCLUDE)/utils.h 
	
	g++ -c -o $(OBJ)/utils.o $(SRC)/utils.cpp -I./include -std=c++14
	
$(LIB)/libClaseEncar.a : $(OBJ)/utils.o $(OBJ)/ClaseEncar.o            
	
	ar -rvs $(LIB)/libClaseEncar.a $(OBJ)/utils.o $(OBJ)/ClaseEncar.o 

$(OBJ)/ClaseEncar.o: $(SRC)/Encargos.cpp $(INCLUDE)/utils.h \
                     $(INCLUDE)/Encargos.h 
	
	g++ -c -o $(OBJ)/ClaseEncar.o $(SRC)/Encargos.cpp -I./include \
	          -std=c++14
	
$(LIB)/libClaseAdscrip.a : $(OBJ)/ClaseAdscrip.o  $(OBJ)/utils.o           
	
	ar -rvs $(LIB)/libClaseAdscrip.a $(OBJ)/utils.o $(OBJ)/ClaseAdscrip.o

$(OBJ)/ClaseAdscrip.o : $(INCLUDE)/utils.h \
                        $(INCLUDE)/Adscripcion.h
	
	g++ -c -o $(OBJ)/ClaseAdscrip.o $(SRC)/Adscripcion.cpp -I./include \
	          -std=c++14		

$(LIB)/libVectorDepartamento.a : $(OBJ)/VectorDepartamento.o \
                                 $(OBJ)/ClaseDepart.o $(OBJ)/utils.o           
	
	ar -rvs $(LIB)/libVectorDepartamento.a $(OBJ)/VectorDepartamento.o\
	        $(OBJ)/ClaseDepart.o $(OBJ)/utils.o

$(OBJ)/VectorDepartamento.o : $(INCLUDE)/VectorDepartamento.h \
                              $(INCLUDE)/Departamento.h
	
	g++ -c -o $(OBJ)/VectorDepartamento.o $(SRC)/VectorDepartamento.cpp\
	       -I./include -std=c++14

$(LIB)/libVectorProfesor.a : $(OBJ)/VectorProfesor.o \
                             $(OBJ)/ClaseProf.o $(OBJ)/utils.o           
	
	ar -rvs $(LIB)/libVectorProfesor.a $(OBJ)/VectorProfesor.o\
	        $(OBJ)/ClaseProf.o $(OBJ)/utils.o

$(OBJ)/VectorProfesor.o : $(INCLUDE)/VectorProfesor.h  $(INCLUDE)/Profesor.h
	
	g++ -c -o $(OBJ)/VectorProfesor.o $(SRC)/VectorProfesor.cpp\
	       -I./include -std=c++14

$(LIB)/libVectorAdscripcion.a : $(OBJ)/VectorAdscripcion.o \
                             $(OBJ)/ClaseAdscrip.o $(OBJ)/utils.o           
	
	ar -rvs $(LIB)/libVectorAdscripcion.a $(OBJ)/VectorAdscripcion.o\
	        $(OBJ)/ClaseAdscrip.o $(OBJ)/utils.o

$(OBJ)/VectorAdscripcion.o : $(INCLUDE)/VectorAdscripcion.h  \
                             $(INCLUDE)/Adscripcion.h
	
	g++ -c -o $(OBJ)/VectorAdscripcion.o $(SRC)/VectorAdscripcion.cpp\
	       -I./include -std=c++14

$(LIB)/libVectorEncargo.a : $(OBJ)/VectorEncargo.o \
                            $(OBJ)/ClaseEncar.o $(OBJ)/utils.o           
	
	ar -rvs $(LIB)/libVectorEncargo.a $(OBJ)/VectorEncargo.o\
	        $(OBJ)/ClaseEncar.o $(OBJ)/utils.o

$(OBJ)/VectorEncargo.o : $(INCLUDE)/VectorEncargo.h  \
                         $(INCLUDE)/Encargos.h
	
	g++ -c -o $(OBJ)/VectorEncargo.o $(SRC)/VectorEncargo.cpp\
	       -I./include -std=c++14

clean:
	-rm $(OBJ)/*
	@echo Objetos borrados
	
mr.proper: clean 
	-rm $(BIN)/*
	-rm $(LIB)/*
	@echo Ejecutables borrados
	
	
	
