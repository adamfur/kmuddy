
add_subdirectory( plugins )

include_directories( ${CMAKE_SOURCE_DIR}/libs ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )

add_definitions (-DQT3_SUPPORT)
add_definitions (-DQT3_SUPPORT_WARNINGS)


########### next target ###############

set(kmuddymapper_PART_SRCS 
   kmuddy_mapper.cpp 
   cmaptoolbase.cpp 
   cmaplevel.cpp 
   cmapview.cpp 
   cmapwidget.cpp 
   cmapdata.cpp 
   cmapelement.cpp 
   cmappath.cpp 
   cmaproom.cpp 
   cmapzone.cpp 
   cmaptext.cpp 
   cmapelementutil.cpp
   cmapviewstatusbar.cpp 
   cmaplistviewitem.cpp 
   cmapcmdgroup.cpp 
   cmapcmdelementcreate.cpp 
   cmapcmdelementproperties.cpp 
   cmapcmdelementdelete.cpp 
   cmapcmdtogglepathtwoway.cpp 
   cmapcmdmovemap.cpp 
   cmapcmdmoveplayer.cpp 
   cmapcmdleveldelete.cpp 
   cmapcmdlevelcreate.cpp 
   cmappropertiespanebase.cpp 
   cmappluginbase.cpp 
   cmapfilter.cpp 
   cmapfilefilterbase.cpp 
   cmapcommand.cpp 
   cmapclipboard.cpp 
   cmapzonemanager.cpp 
   kmemconfig.cpp 
   cmapmanager.cpp
   dialogs/dlgmapmovement.cpp
   dialogs/dlgmaptextproperties.cpp
   dialogs/dlgmaproomproperties.cpp
   dialogs/dlgmappathproperties.cpp
   dialogs/dlgspeedwalkprogress.cpp
   dialogs/dlgmapcolor.cpp
   dialogs/dlgmapspeedwalk.cpp
   dialogs/dlgmapdirections.cpp 
   filefilters/cmapfilefilterxml.cpp
   )

kde4_add_ui_files (kmuddymapper_PART_SRCS
   dialogs/dlgmapcolorbase.ui
   dialogs/dlgmapmovementbase.ui
   dialogs/dlgmapspeedwalkbase.ui
   dialogs/dlgmaptextpropertiesbase.ui
   dialogs/dlgmaproompropertiesbase.ui
   dialogs/dlgmappathpropertiesbase.ui
   dialogs/dlgspeedwalkprogressbase.ui
   dialogs/dlgmapdirectionsbase.ui
   )

kde4_add_plugin(kmuddymapper ${kmuddymapper_PART_SRCS})

target_link_libraries(kmuddymapper  ${KDE4_KDECORE_LIBS} ${KDE4_KPARTS_LIBS} ${KDE4_KDE3SUPPORT_LIBS} kmuddycore )

install(TARGETS kmuddymapper DESTINATION ${PLUGIN_INSTALL_DIR} )


########### install files ###############

install( FILES kmuddymapper.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kmuddymapperpart.rc DESTINATION ${DATA_INSTALL_DIR}/kmuddy )
install( FILES kmuddymapperplugin.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )
install( FILES kmud_grid.png kmud_create.png kmud_follow.png DESTINATION ${DATA_INSTALL_DIR}/kmuddy/toolbar )

