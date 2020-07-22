******************************************************************************
* @file    readme.txt
* @author  MCD Application Team
* @version V1.1
* @date    27-September-2018 
* @brief   Accelerated Designs multiple EDA CAD tools format (.bxl) files
*          for the STM32F1x MCUs.
******************************************************************************
* COPYRIGHT(c) 2017 STMicroelectronics
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************

=======================
How to use .bxl files :
=======================

The Ultra Librarian software is a free reader from Accelerated Designs which
allows the user to view the .bxl files. It also allows the user to create symbols
and footprints for most common CAD tools. For further information, please visit
first http://www.accelerated-designs.com/.

The process to use a .bxl file is detailed below:
1. Download and install the Ultra Librarian reader.
2. Unzip the zip filed of the desired product series.
3. Open the appropriate .bxl ( the Ultra Librarian software will open automatically).
4. Export the file to the desired PCB/CAD format.

The package contains :
   + A .bxl file for each STM32F1x device or generic sub-family (x) in the different existing packages
	  o Check your device part number and select it from the list
   + A .xlsx file containing the correspondance between part number and .bxl file

==========================
* V1.1 - 27-September-2018
==========================

Changing names assignment for all bxl files directly corresponding to product salestypes.
No more SelectBXLFile file needed.
Here is the new list:


	STM32F103V8Hx
	STM32F103VBHx
	STM32F103VCHx
	STM32F103VDHx
	STM32F103VEHx
	STM32F105V8Hx
	STM32F105VBHx
	STM32F107VCHx
	STM32F103ZCHx
	STM32F103ZDHx
	STM32F103ZEHx
	STM32F103ZFHx
	STM32F103ZGHx
	STM32F100V8Tx
	STM32F100VBTx
	STM32F100VCTx
	STM32F100VDTx
	STM32F100VETx
	STM32F101V8Tx
	STM32F101VBTx
	STM32F101VCTx
	STM32F101VDTx
	STM32F101VETx
	STM32F101VFTx
	STM32F101VGTx
	STM32F103V8Tx
	STM32F103VBTx
	STM32F103VCTx
	STM32F103VDTx
	STM32F103VETx
	STM32F103VFTx
	STM32F103VGTx
	STM32F105V8Tx
	STM32F105VBTx
	STM32F105VCTx
	STM32F107VBTx
	STM32F107VCTx
	STM32F100ZCTx
	STM32F100ZDTx
	STM32F100ZETx
	STM32F101ZCTx
	STM32F101ZDTx
	STM32F101ZETx
	STM32F101ZFTx
	STM32F101ZGTx
	STM32F103ZCTx
	STM32F103ZDTx
	STM32F103ZETx	
	STM32F103ZFTx
	STM32F103ZGTx
	STM32F100C4Tx
	STM32F100C6Tx
	STM32F100C8Tx
	STM32F100CBTx
	STM32F101C4Tx
	STM32F101C6Tx
	STM32F101C8Tx
	STM32F101CBTx
	STM32F102C4Tx
	STM32F102C6Tx
	STM32F102C8Tx
	STM32F102CBTx
	STM32F103C4Tx
	STM32F103C6Tx
	STM32F103C8Tx
	STM32F103CBTx
	STM32F100R4Tx
	STM32F100R6Tx
	STM32F100R8Tx
	STM32F100RBTx
	STM32F100RCTx
	STM32F100RDTx
	STM32F100RETx
	STM32F101R4Tx
	STM32F101R6Tx
	STM32F101R8Tx
	STM32F101RBTx
	STM32F101RCTx
	STM32F101RDTx
	STM32F101RETx
	STM32F101RFTx
	STM32F101RGTx	
	STM32F102R4Tx
	STM32F102R6Tx
	STM32F102R8Tx
	STM32F102RBTx
	STM32F103R4Tx
	STM32F103R6Tx
	STM32F103R8Tx
	STM32F103RBTx
	STM32F103RCTx
	STM32F103RDTx
	STM32F103RETx
	STM32F103RFTx
	STM32F103RGTx
	STM32F105R8Tx
	STM32F105RBTx
	STM32F105RCTx
	STM32F107RBTx
	STM32F107RCTx
	STM32F100R4Hx
	STM32F100R6Hx
	STM32F100R8Hx
	STM32F100RBHx
	STM32F101RBHx
	STM32F103R4Hx
	STM32F103R6Hx
	STM32F103R8Hx
	STM32F103RBHx
	STM32F103VBIx
	STM32F101C8Ux
	STM32F101CBUx
	STM32F103C6Ux
	STM32F103CBUx
	STM32F101T4Ux
	STM32F101T6Ux
	STM32F101T8Ux
	STM32F101TBUx
	STM32F103T4Ux
	STM32F103T6Ux
	STM32F103T8Ux
	STM32F103TBUx
	STM32F103RCYx
	STM32F103RDYx
	STM32F103REYx


==========================
* V1.0 - 20-January-2017
==========================
  Created.

   + STM32F10xCxT1
   + STM32F10xRxT1
   + STM32F10xRxH
   + STM32F10xRxT2
   + STM32F10xVxT1
   + STM32F10xVxT2
   + STM32F10xZxT
   + STM32F10xCxU
   + STM32F10xTxU
   + STM32F102RxT3
   + STM32F103CxT2
   + STM32F10xRxY
   + STM32F103VxH
   + STM32F103VBI
   + STM32F103ZxH

  

******************* (C) COPYRIGHT 2017 STMicroelectronics *****END OF FILE
