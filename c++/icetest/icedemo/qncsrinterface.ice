module csr
{
    interface ResultCallbackProxy
    {
        void sendStreamResult(string sessionid,string result);
    };

};
