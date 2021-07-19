extern void mDelayuS(unsigned char us);

void mDelaymS( unsigned char ms )
{
  while (ms) 
  {  
	   mDelayuS(250);
     mDelayuS(250);
     mDelayuS(250);
     mDelayuS(250);
	   -- ms;
  }
}